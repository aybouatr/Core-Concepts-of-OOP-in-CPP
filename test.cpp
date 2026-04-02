#include <iostream>




#include <iostream>
using namespace std;

int main() 
{
    try
    {
        try 
        {
            cout << "Before throw\n";
            throw 10;
            cout << "After throw\n"; // ❌ will NOT run
        }
        catch (char x) 
        {
            cout << "Caught: inside  " << x << std::endl;
        }
        catch (int x) 
        {
            cout << "Caught: 11 inside  " << x << std::endl;
        }
        std::cout << "when i go outside the block ";
    }
    catch(int e)
    {
            cout << "Caught: outside " << e << std::endl;
    }
    
   
}



// class test :
// {
// private:
   
// public:
//     test(/* args */);
//     ~test();
// };

// test::test(/* args */)
// {
// }

// test::~test()
// {
// }
