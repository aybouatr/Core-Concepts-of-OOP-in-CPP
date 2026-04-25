#include "../include/PmergeMe1.hpp"
#include <algorithm>
#include <climits>


PmergeMe::PmergeMe(int argc, char **argv)
{
    if (argc < 2)
        throw std::runtime_error("Usage: ./PmergeMe <positive integers...>");

    for (int i = 1; i < argc; ++i) {
        std::istringstream ss(argv[i]);
        long val;
        if (!(ss >> val) || !ss.eof())
            throw std::runtime_error("Error: invalid input '" + std::string(argv[i]) + "'");
        if (val <= 0)
            throw std::runtime_error("Error: not a positive integer '" + std::string(argv[i]) + "'");
        if (val > INT_MAX)
            throw std::runtime_error("Error: number too large '" + std::string(argv[i]) + "'");
        _input.push_back(static_cast<int>(val));
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// buildInsertOrder
// Produces the Jacobsthal-ordered slot list.
// Slot 1      = a1 (free, skip it)
// Slots 2..m  = a2..am (the losers)
// Slot m+1    = leftover (if n is odd)
//
// Within each group (defined by consecutive Jacobsthal boundaries)
// insert RIGHT→LEFT so that each insertion bounds the next.
// ─────────────────────────────────────────────────────────────────────────────

std::vector<int> PmergeMe::buildInsertOrder(int numPairs, bool hasLeftover)
{
    int totalSlots = numPairs + (hasLeftover ? 1 : 0);
    if (totalSlots <= 1)
       return std::vector<int>();

    // Build Jacobsthal sequence up to totalSlots
    std::vector<int> jac;
    jac.push_back(1);
    jac.push_back(3);
    while (true) 
    {
        int nx = jac[jac.size()-1] + 2 * jac[jac.size() - 2];
        if (nx > totalSlots + 10) break;
        jac.push_back(nx);
    }

    std::vector<int> order;
    std::vector<bool> used(totalSlots + 1, false);
    used[1] = true;   // slot 1 = a1, already free

    int prevBound = 1;
    for (int ji = 1; ji < static_cast<int>(jac.size()); ++ji) {
        int hi = std::min(jac[ji], totalSlots);
        if (hi <= prevBound) continue;

        // Insert right-to-left within this group
        for (int i = hi; i > prevBound; --i) {
            if (i >= 2 && i <= totalSlots && !used[i]) {
                order.push_back(i);
                used[i] = true;
            }
        }
        prevBound = jac[ji];
        if (prevBound >= totalSlots) break;
    }
    // Any remaining slots (shouldn't normally happen)
    for (int i = totalSlots; i >= 2; --i)
        if (!used[i]) { order.push_back(i); used[i] = true; }

    return order;
}

// ─────────────────────────────────────────────────────────────────────────────
// printResult
// ─────────────────────────────────────────────────────────────────────────────

void PmergeMe::printResult(const std::string &label,
                           const std::vector<int> &sorted,
                           unsigned int comps,
                           double microsec,
                           const std::string &containerName) const
{
    (void)label;
    std::cout << "Time to process a range of " << sorted.size()
              << " elements with " << containerName << " : "
              << microsec << " us"
              << "  [comparisons: " << comps << "]"
              << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// run — entry point
// ─────────────────────────────────────────────────────────────────────────────
void PmergeMe::run()
{
    int n = static_cast<int>(_input.size());

    // ── Print unsorted sequence ───────────────────────────────────────────────
    std::cout << "Before:";
    for (int i = 0; i < n; ++i)
        std::cout << " " << _input[i];
    std::cout << std::endl;

    // ── std::vector run ───────────────────────────────────────────────────────

    unsigned int  vecComps = 0;
    double        vecTime  = 0.0;

    std::vector<int> vecResult;
    {
        unsigned int counter = 0;

        std::vector<Counted> v;

        for (int i = 0; i < n; ++i)
            v.push_back(Counted(_input[i], &counter));

        std::clock_t t0 = std::clock();

        vecComps = fordJohnson(v);
        
        std::clock_t t1 = std::clock();
        vecTime  = static_cast<double>(t1 - t0) / CLOCKS_PER_SEC * 1e6;

        for (int i = 0; i < n; ++i)
            vecResult.push_back(v[i].value);
    }

    // ── Print sorted sequence (use vector result) ─────────────────────────────
    std::cout << "After:";
    for (int i = 0; i < n; ++i)
        std::cout << " " << vecResult[i];
        
    std::cout << std::endl;

    // ── std::deque run ────────────────────────────────────────────────────────
    unsigned int deqComps = 0;
    double       deqTime  = 0.0;

    std::vector<int> deqResult;
    {
        unsigned int counter = 0;
        std::deque<Counted> d;
        for (int i = 0; i < n; ++i)
            d.push_back(Counted(_input[i], &counter));

        std::clock_t t0 = std::clock();
        deqComps = fordJohnson(d);
        std::clock_t t1 = std::clock();
        deqTime  = static_cast<double>(t1 - t0) / CLOCKS_PER_SEC * 1e6;

        for (int i = 0; i < n; ++i)
            deqResult.push_back(d[i].value);
    }

    // ── Print timing + comparison counts ─────────────────────────────────────

    printResult("", vecResult, vecComps, vecTime, "std::vector");
    printResult("", deqResult, deqComps, deqTime, "std::deque");

    // ── Verify both containers agree ──────────────────────────────────────────
    if (vecResult != deqResult) {
        std::cerr << "Error: vector and deque produced different results!" << std::endl;
    }
}
 