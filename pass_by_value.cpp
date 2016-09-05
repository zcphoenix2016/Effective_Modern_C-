#include <iostream>

class Widget
{
public:
    Widget()
    {
        std::cout << "Widget constructor." << std::endl;
    }
    ~Widget()
    {
        std::cout << "Widget destructor." << std::endl;
    }
    Widget& operator=(const Widget& rhs)
    {
        std::cout << "Widget copy assignment operator." << std::endl;
    }
    Widget(const Widget& rhs)
    {
        std::cout << "Widget copy constructor." << std::endl;
    }
    Widget(Widget&& rhs)
    {
        std::cout << "Widget move constructor." << std::endl;
    }
    Widget& operator=(Widget&& rhs)
    {
        std::cout << "Widget move assignment operator." << std::endl;
    }
};

class Foo
{
public:
    Foo()
    {
        std::cout << "Foo constructor." << std::endl;
    }
    ~Foo()
    {
        std::cout << "Foo destructor." << std::endl;
    }
    void setWidget(Widget w)
    {
        m_w = std::move(w);
    }
private:
    Widget m_w;
};

int main()
{
    Foo f;
    std::cout << "---------------------" << std::endl;
    Widget w;
    std::cout << "---------------------" << std::endl;
    f.setWidget(w);
    std::cout << "---------------------" << std::endl;
    f.setWidget(Widget());
    std::cout << "---------------------" << std::endl;

    return 0;
}
