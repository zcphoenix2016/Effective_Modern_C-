#include <iostream>
#include <functional>

class Foo
{
public:
    explicit Foo(int x) : m_x(x)
    {
        std::cout << "Constructor with x = " << x << std::endl;
    }

    int m_x = 0;
};

void func(int param)
{
    std::cout << "param = " << param << std::endl;
}

void func(Foo param)
{
    std::cout << "Foo with x = " << param.m_x << std::endl;
}

struct S
{
    unsigned char a : 4;
    unsigned char b : 3;
};

int main()
{
    int x = 100;
    int& xr = x;
    int&& xrr = std::move(x);
    //int& & xr_r = xr; reference to reference is forbidden

    func(x);
    func(xr);
    func(xrr);
    func(100);

    //func(100); explicit constructor forbids implicit conversion
    func(Foo(100));

    S s;
    s.a = 15;
    s.b = 7;
    std::cout << "size of S = " << sizeof(S) << ", s.a = " << (int)s.a << ", s.b = " << (int)s.b << std::endl;

    std::cout << std::boolalpha;
    auto fv = [y=x](){return y == 100;};
    std::cout << fv() << std::endl;

    auto fr = [&y = x](){y = 200;};
    std::cout << "Initially x = " << x << std::endl;
    fr();
    std::cout << "After lambda x = " << x << std::endl;

    auto le = std::less_equal<int>();
    std::cout << "std::less_equal<int>(10, 20): " << le(10, 20) << std::endl;
    std::cout << "std::less_equal<int>(20, 10): " << le(20, 10) << std::endl;

    using namespace std::placeholders;
    auto leB = std::bind(std::less_equal<int>(), _1, _2);
    std::cout << "std::less_equal<int>(10, 20): " << leB(10, 20) << std::endl;
    std::cout << "std::less_equal<int>(20, 10): " << leB(20, 10) << std::endl;
    std::cout << std::noboolalpha;


    return 0;
}
