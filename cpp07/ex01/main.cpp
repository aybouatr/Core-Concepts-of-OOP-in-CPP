#include "include/iter.hpp"

#include <iostream>
#include <string>
#include <iostream>
#include <string>


template <typename T>

void print(const T& x)
{
    std::cout << x << " ";
}

void increment(int& x)
{
    x++;
}

void toUpper(char& c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

template <typename T>
void multiplyByTwo(T& x)
{
    x *= 2;
}

template <typename T>
void printConst(const T& x)
{
    std::cout << "[" << x << "] ";
}

class Awesome
{
public:
    Awesome(int n = 0) : _n(n) {}
    int get() const { return _n; }

    bool operator<(const Awesome& other) const { return _n < other._n; }

private:
    int _n;
};

std::ostream& operator<<(std::ostream& o, const Awesome& a)
{
    o << a.get();
    return o;
}


int main()
{

    std::cout << "===== TEST 1: int print =====\n";
    int arr1[] = {1, 2, 3, 4, 5};
    iter::iter(arr1, 5, print<int>);
    std::cout << "\n\n";


    std::cout << "===== TEST 2: int modify =====\n";
    iter::iter(arr1, 5, increment);
    iter::iter(arr1, 5, print<int>);
    std::cout << "\n\n";

    std::cout << "===== TEST 3: char modify =====\n";
    char arr2[] = {'a', 'b', 'c', 'd'};
    iter::iter(arr2, 4, toUpper);
    iter::iter(arr2, 4, print<char>);
    std::cout << "\n\n";

    std::cout << "===== TEST 4: string =====\n";
    std::string arr3[] = {"hello", "world"};
    iter::iter(arr3, 2, print<std::string>);
    std::cout << "\n\n";

    std::cout << "===== TEST 5: template func =====\n";
    int arr4[] = {2, 4, 6};
    iter::iter(arr4, 3, multiplyByTwo<int>);
    iter::iter(arr4, 3, print<int>);
    std::cout << "\n\n";

    std::cout << "===== TEST 6: const array =====\n";
    const int arr5[] = {10, 20, 30};
    iter::iter(arr5, 3, printConst<int>);
    std::cout << "\n\n";
   
    std::cout << "===== TEST 9: custom class =====\n";
    Awesome arr8[] = {1, 2, 3};
    iter::iter(arr8, 3, print<Awesome>);
    std::cout << "\n\n";

    std::cout << "===== TEST 10: empty array =====\n";
    int* empty = NULL;
    iter::iter(empty, 0, print<int>); 
    std::cout << "\n\n";

    return 0;
} 