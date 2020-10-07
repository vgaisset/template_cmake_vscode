#include <iostream>
#include <MyClass.hpp>

int main(int, char**) 
{
    std::cout << MyClass().Hello() << std::endl;
    return 0;
}