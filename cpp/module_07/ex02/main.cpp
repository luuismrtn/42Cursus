#include <iostream>
#include "./inc/Array.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
    try
    {
        std::cout << "\t --Test Integer Array-- \n";
        Array<int> intArray(5);
        for (int i = 0; i < 5; ++i)
            intArray[i] = i * 10;
        std::cout << intArray.size() << std::endl;
        for (unsigned int i = 0; i < intArray.size(); ++i)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "\t--Test String Array--\n";
        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        std::cout << strArray.size() << std::endl;
        for (unsigned int i = 0; i < strArray.size(); ++i)
            std::cout << strArray[i] << " ";
        std::cout << std::endl;
        std::cout << strArray.size() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Array<int> intArray(5);
        for (int i = 0; i < 5; ++i)
            intArray[i] = i * 10;
        std::cout << "\t--Test fail-- \n";
        std::cout << intArray.size() << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
