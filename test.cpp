#include <iostream>
#include <exception>


#include <iostream>
using namespace std;

// int main() 
// {
//     double num = 256;

//     char* bytePtr = reinterpret_cast<char*>(&num);

//     cout << "Bytes of num:" << endl;

//     for (size_t i = 0; i < sizeof(num); ++i) {
//         printf("Byte %zu: 0x%02X\n", i, static_cast<unsigned char>(bytePtr[i]));
//     }


//     char * arr = "ayoub !";

//     double res = reinterpret_cast<double>(&arr);

//     cout << " num:" << endl;

//     cout << res << endl;

//     return 0;
// }

#include <iostream>
#include <cstdint>  // for uintptr_t
using namespace std;


// 1 ) Static Cast
// 2 ) Dynamic Cast
// 3 ) Const Cast
// 4 ) Reinterpret Cast

//=============================

// static_cast<new_type>(expression);
// dynamic_cast<new_type>(expression);
// const_cast<new_type>(expression);
// reinterpret_cast<new_type>(expression);

int main() 
{

    //128 = 64 32 16 8 4 2 1 = 255 ==>
    // 45 = 0  32  0 8 4 0 1      ===>

    long num = 510;

    short shortNum = static_cast<short>(num);

    cout << "Short num: " << shortNum << " size: " << sizeof(shortNum) << endl;

    for (size_t i = 0; i < sizeof(shortNum); ++i) 
    {
        printf("Byte %zu: 0x%02X\n", i, static_cast<unsigned char>(reinterpret_cast<char*>(&shortNum)[i]));
        
    }
    return 0;
}