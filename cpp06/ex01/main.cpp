#include <iostream>
#include "include/Serializer.hpp"



// int main()
// {
//     Data data;

//     data.id = 42;
//     data.name = "Test";

//     Data* originalPtr = &data;

//     uintptr_t raw = Serializer::serialize(originalPtr);

//     Data* deserializedPtr = Serializer::deserialize(raw);


//     std::cout << "Orj pointer : " << originalPtr << std::endl;
//     std::cout << "Srj value   : " << raw << std::endl;
//     std::cout << "Dsrj pointer: " << deserializedPtr << std::endl;


//     if (originalPtr == deserializedPtr)
//         std::cout << "✅ Success  : Pointers match!" << std::endl;
//     else
//         std::cout << "❌ Error    : Pointers do not match!" << std::endl;

//     std::cout << "Data ID     : " << deserializedPtr->id << std::endl;
//     std::cout << "Data Name   : " << deserializedPtr->name << std::endl;

//     return 0;
// }


#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    
    int* mirror = new int[MAX_VAL];
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}