
#include <algorithm>
#include <vector>
#include <list>
#include <climits>  
#include <cfloat>   
#include <iostream>
#include <stack>

template <class T>
class MyStack : public std::stack<T> 
{
    public:
        auto begin()
        { 
            return this->c.begin();
        }
        auto end() 
        { 
            return this->c.end();
        }
};

using namespace std;


int main()
{
    
  MyStack<int> _Mystack ;


   _Mystack.push(12);
   _Mystack.push(10);
   _Mystack.push(9);
   _Mystack.push(13);

   cout << _Mystack.top() << endl;
   auto it = _Mystack.begin();

   cout << " begin " << *it <<  endl;
   cout << " begin " << *(++it) << endl;

}
   







































// #include <iostream>
// using namespace std;

// // int main() 
// // {
// //     double num = 256;

// //     char* bytePtr = reinterpret_cast<char*>(&num);

// //     cout << "Bytes of num:" << endl;

// //     for (size_t i = 0; i < sizeof(num); ++i) {
// //         printf("Byte %zu: 0x%02X\n", i, static_cast<unsigned char>(bytePtr[i]));
// //     }


// //     char * arr = "ayoub !";

// //     double res = reinterpret_cast<double>(&arr);

// //     cout << " num:" << endl;

// //     cout << res << endl;

// //     return 0;
// // }

// #include <iostream>
// #include <cstdint>  // for uintptr_t
// using namespace std;


// // 1 ) Static Cast
// // 2 ) Dynamic Cast
// // 3 ) Const Cast
// // 4 ) Reinterpret Cast

// //=============================

// // static_cast<new_type>(expression);
// // dynamic_cast<new_type>(expression);
// // const_cast<new_type>(expression);
// // reinterpret_cast<new_type>(expression);

// #include <iostream>
// #include <climits>  // INT_MAX
// #include <cfloat>   // FLT_MAX

// int main()
// {
//     std::cout << "Max int: " << INT_MAX << std::endl;
//     std::cout << "Max float: " << FLT_MAX << std::endl;

//     return 0;
// }
// #include <iostream>
// using namespace std;

// // int main() 
// // {
// //     double num = 256;

// //     char* bytePtr = reinterpret_cast<char*>(&num);

// //     cout << "Bytes of num:" << endl;

// //     for (size_t i = 0; i < sizeof(num); ++i) {
// //         printf("Byte %zu: 0x%02X\n", i, static_cast<unsigned char>(bytePtr[i]));
// //     }


// //     char * arr = "ayoub !";

// //     double res = reinterpret_cast<double>(&arr);

// //     cout << " num:" << endl;

// //     cout << res << endl;

// //     return 0;
// // }

// #include <iostream>
// #include <cstdint>  // for uintptr_t
// using namespace std;


// // 1 ) Static Cast
// // 2 ) Dynamic Cast
// // 3 ) Const Cast
// // 4 ) Reinterpret Cast

// //=============================

// // static_cast<new_type>(expression);
// // dynamic_cast<new_type>(expression);
// // const_cast<new_type>(expression);
// // reinterpret_cast<new_type>(expression);

// #include <iostream>
// #include <climits>  // INT_MAX
// #include <cfloat>   // FLT_MAX

// int main()
// {
//     std::cout << "Max int: " << INT_MAX << std::endl;
//     std::cout << "Max float: " << FLT_MAX << std::endl;

//     return 0;
// }