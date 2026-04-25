#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>

// ─────────────────────────────────────────────────────────────────────────────
// Wrapper type: every element carries a comparison counter.
// Overloading operator< lets us count every single comparison automatically,
// no matter where it happens inside the sort (binary search, pair compare, etc.)
// ─────────────────────────────────────────────────────────────────────────────
struct Counted 
{
    int          value;
    unsigned int *counter;

    Counted() : value(0), counter(NULL)
    {

    }
    Counted(int v, unsigned int *c) : value(v), counter(c) 
    {

    }

    // Every < comparison increments the shared counter

    bool operator<(const Counted &rhs) const 
    {
        if (counter) 
            ++(*counter);
        return value < rhs.value;
    }

    bool operator>(const Counted &rhs)  const
    { 
        return rhs < *this;
    }

    bool operator<=(const Counted &rhs) const 
    
    { 
        return !(rhs < *this); 
    }
    
    bool operator>=(const Counted &rhs) const 
    
    { 
        return !(*this < rhs); 
    }

    bool operator==(const Counted &rhs) const 
    
    { 
        return value == rhs.value; 
    }

};

// ─────────────────────────────────────────────────────────────────────────────
// Main class — holds both a vector and a deque version
// ─────────────────────────────────────────────────────────────────────────────
class PmergeMe 
{
public:
    explicit PmergeMe(int argc, char **argv);

    void run();

private:
    std::vector<int> _input;   // raw parsed input

    // ── Jacobsthal sequence ──────────────────────────────────────────────────
    // t_k = (2^(k+1) + (-1)^k) / 3  →  recurrence: t_k = t_{k-1} + 2*t_{k-2}
    // Returns the flat insertion-order list for totalSlots slots
    // (slot 1 = a1 free; if n odd, slot numPairs+1 = leftover)
    static std::vector<int> buildInsertOrder(int numPairs, bool hasLeftover);

    // ── Templated Ford-Johnson ───────────────────────────────────────────────
    // Works on any random-access container<Counted>.
    // Returns number of comparisons used.
    
    template <typename Container>
    static unsigned int fordJohnson(Container &seq);

    // Internal recursive helper (operates on a sub-range via indices)
    template <typename Container>
    static void fjSort(Container &seq, int lo, int hi);

    // Lower-bound binary insert of val into seq[lo..hi) — returns # comparisons
    template <typename Container>
    static int binaryInsert(Container &seq, int lo, int hi,
                            typename Container::value_type val);

    void printResult(const std::string &label,
                     const std::vector<int> &sorted,
                     unsigned int comps,
                     double microsec,
                     const std::string &containerName) const;
};

// ─────────────────────────────────────────────────────────────────────────────
// Template implementations (must be in header for C++98)
// ─────────────────────────────────────────────────────────────────────────────

template <typename Container>
unsigned int PmergeMe::fordJohnson(Container &seq)
{
    int n = static_cast<int>(seq.size());
    if (n <= 1)
      return 0;

    // share one counter across all Counted elements so operator< accumulates
    unsigned int counter = 0;

    for (int i = 0; i < n; ++i)
        seq[i].counter = &counter;

    fjSort(seq, 0, n - 1);
    return counter;
}

// ── fjSort: Ford-Johnson over seq[lo..hi] inclusive ─────────────────────────

template <typename Container>
void PmergeMe::fjSort(Container &seq, int lo, int hi)
{
    int n = hi - lo + 1;
    if (n <= 1)
      return;

    // ── Step 1: pairwise comparisons ─────────────────────────────────────────
    // Compare adjacent pairs (lo,lo+1), (lo+2,lo+3), ...
    // Ensure seq[lo+2k] <= seq[lo+2k+1]  (winner at even index, loser at odd)
    // We store pairs as (winner, loser) with winner at position lo+2k
    // Then sort the sub-array of winners.
    //
    // Implementation strategy for in-place:
    //   Re-arrange so pairs are stored as (winner, loser) side by side,
    //   then recurse on every other element (the winners).
    //   After recursion, rebuild loser associations and do the insertions.
    //
    // For clarity we use the "paired index" approach:
    //   - pair up: seq[lo], seq[lo+1]; seq[lo+2], seq[lo+3]; ...
    //   - bring the larger of each pair to the front of the pair
    //   - recurse on the winners (positions lo, lo+2, lo+4, ...)
    //   - then insert losers using Jacobsthal order

    bool hasLeftover = (n % 2 == 1);
    int  numPairs    = n / 2;

    // ── Step 1a: sort each pair so seq[lo+2k] > seq[lo+2k+1] ────────────────
    for (int i = 0; i < numPairs; ++i) {
        int wi = lo + 2 * i;
        int li = lo + 2 * i + 1;
        if (seq[wi] < seq[li])                      // 1 comparison per pair
            std::swap(seq[wi], seq[li]);
        // now seq[wi] >= seq[li]  (winner at wi, loser at li)
    }

    // ── Step 2: recursively sort winners ─────────────────────────────────────
    // Winners are at positions lo, lo+2, lo+4, ..., lo+2*(numPairs-1)
    // We can't recurse in-place easily without copying, so we copy winners,
    // recurse, then rebuild.
    typedef typename Container::value_type T;

    // Extract winners (store their original loser values alongside)
    std::vector<std::pair<T, T> > pairs(numPairs);
    for (int i = 0; i < numPairs; ++i) {
        pairs[i].first  = seq[lo + 2 * i];       // winner (b_i)
        pairs[i].second = seq[lo + 2 * i + 1];   // loser  (a_i)
    }
    T leftoverVal;
    if (hasLeftover)
        leftoverVal = seq[hi];

    // Recursively sort the winners (first element of each pair)
    Container winners;
    for (int i = 0; i < numPairs; ++i)
        winners.push_back(pairs[i].first);
    fjSort(winners, 0, numPairs - 1);

    // Rebuild pairs: each winner now has a position in sorted order;
    // re-associate with its loser (winners and losers stay bound to original pair)
    // After winner sort, winners[i] is the i-th smallest winner.
    // We need to know which loser belonged to which winner.
    // Since we only compare values (no extra id), find the loser by winner value.
    // (Input is distinct integers so this is safe.)
    std::vector<T> sortedLosers(numPairs);
    {
        // mark used to handle duplicates safely
        std::vector<bool> used(numPairs, false);
        for (int i = 0; i < numPairs; ++i) {
            for (int j = 0; j < numPairs; ++j) {
                if (!used[j] && winners[i] == pairs[j].first) {
                    sortedLosers[i] = pairs[j].second;
                    used[j] = true;
                    break;
                }
            }
        }
    }

    // ── Step 3: build main chain [a1, b1, b2, ..., bm] ──────────────────────
    // a1 (sortedLosers[0]) is FREE because a1 < b1 (guaranteed from pairing)
    Container chain;
    chain.push_back(sortedLosers[0]);           // a1 — free, no comparison
    for (int i = 0; i < numPairs; ++i)
        chain.push_back(winners[i]);            // b1, b2, ..., bm

    // DO NOT put leftover here — it gets a Jacobsthal slot below

    // ── Step 4 + 5: Jacobsthal-ordered insertion ─────────────────────────────
    std::vector<int> order = buildInsertOrder(numPairs, hasLeftover);

    for (int oi = 0; oi < static_cast<int>(order.size()); ++oi) {
        int slot   = order[oi];
        bool isLO  = hasLeftover && (slot == numPairs + 1);
        T    val   = isLO ? leftoverVal : sortedLosers[slot - 1];

        int upperExcl;
        if (isLO) {
            // no paired winner → search full chain
            upperExcl = static_cast<int>(chain.size());
        } else {
            // find paired winner in chain (EXCLUDE it from range → use pos, not pos+1)
            T pairedWinner = winners[slot - 1];
            upperExcl = 0;
            for (int ci = 0; ci < static_cast<int>(chain.size()); ++ci) {
                if (chain[ci] == pairedWinner) {
                    upperExcl = ci;   // NOT ci+1 — exclude the winner itself
                    break;
                }
            }
        }

        // binary insert into chain[0..upperExcl-1]
        int insertPos = 0;
        {
            int loBs = 0, hiBs = upperExcl;
            while (loBs < hiBs) {
                int mid = (loBs + hiBs) / 2;
                if (chain[mid] < val)   // operator< counts this
                    loBs = mid + 1;
                else
                    hiBs = mid;
            }
            insertPos = loBs;
        }
        chain.insert(chain.begin() + insertPos, val);
    }

    // ── Copy sorted chain back into seq[lo..hi] ──────────────────────────────
    for (int i = 0; i < static_cast<int>(chain.size()); ++i)
        seq[lo + i] = chain[i];
}

template <typename Container>
int PmergeMe::binaryInsert(Container &seq, int lo, int hi, typename Container::value_type val)
{
    int comps = 0;
    int l = lo, h = hi;
    while (l < h) {
        int mid = (l + h) / 2;
        ++comps;
        if (seq[mid] < val) l = mid + 1;
        else                h = mid;
    }
    seq.insert(seq.begin() + l, val);
    return comps;
}

#endif