
#include <string>
#include <iostream>

using namespace std;


#include <iostream>
using namespace std;

class base
{
public:

    virtual void func()
    {
        cout << "hello from base A " << endl;
    }
};

class baseB : virtual public base
{
public:
    virtual void func()
    {
        cout << "hello from base B" << endl;
    }
};

class baseC : virtual public base
{
public:
    virtual void func()
    {
        cout << "hello from base C" << endl;
    }
};

class baseD : public baseB, public baseC
{
public:
    virtual void func()
    {
        cout << "hello from base D" << endl;
    }
};

int main()
{
    base* D = new baseB;
    D->func();      // calls baseD::func()
    delete D;
    return 0;
}
