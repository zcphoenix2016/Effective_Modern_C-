#include <string>
#include <utility>
#include <type_traits>
#include <iostream>

std::string nameFromIdx(int idx)
{
    std::cout << "Function nameFromIdx()" << std::endl;
    return std::string("Idx-") + std::to_string(idx);
}

class Person
{
public:
    template<typename T>
    explicit Person(T&& initVal)
    : Person(initVal,
             std::is_integral<std::remove_reference_t<T>>())
    {
        std::cout << "Constructor with universal reference." << std::endl;
    }

    Person(const Person&)
    {
        std::cout << "Copy constructor with const lvalue." << std::endl;
    }
    Person(Person&)
    {
        std::cout << "Copy constructor with non-const lvalue." << std::endl;
    }
    Person(Person&&)
    {
        std::cout << "Move constructor with non-const rvalue." << std::endl;
    }

    std::string getStr() const
    {
        return m_name;
    }

private:
    template<typename T>
    Person(T&& n, std::true_type)
    : Person(nameFromIdx(std::forward<T>(n)))
    {
        std::cout << "Constructor with integral argument." << std::endl;
    }

    template<typename T>
    Person(T&& n, std::false_type)
    : m_name(std::forward<T>(n))
    {
        std::cout << "Constructor with non-integral argument." << std::endl;
    }

    std::string m_name;
};


int main()
{
    const Person p1("man");
    Person p2(10);
    std::cout << "p1: " << p1.getStr() << ", p2: " << p2.getStr() << std::endl;
    
    std::cout << "------------------------------" << std::endl;

    Person p3(p1), p4(p2), p5(std::move(p2));

    return 0;
}
