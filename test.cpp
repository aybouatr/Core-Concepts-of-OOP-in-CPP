
#include <string>
#include <iostream>

using namespace std;


#include <iostream>
using namespace std;

class base
{

    int x = 4;

public:

    

    const int returnx() const
    {
        // x++;
        return x;
    }

   
};

class baseB :  public base
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
   base b;

    const int n = b.returnx();
   std::cout << n << std::endl;


}
