#include <iostream>
#include <vector>
#include <ios>

std::vector<bool> foo()
{
    std::vector<bool> vec{true, false};
    return vec;
}

int main()
{
    std::vector<bool> vecBool{true, true, false, false, true, false};
    std::vector<bool>::reference ref = vecBool[0];
    std::cout << std::boolalpha << ref << std::endl;

    //undefined behavior here !
    //'b' may contain dangling pointer !
    //'b' is not 'bool&' but a reference to some stucture holding the value of bool
    //Here it's a temp vector returned by foo().
    auto b = foo()[1];
    std::cout << std::boolalpha << b << std::endl;

    return 0;
}
