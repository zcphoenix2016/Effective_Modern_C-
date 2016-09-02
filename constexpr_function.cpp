#include <array>
#include <iostream>

class Point
{
public:
    constexpr Point(int xVal, int yVal) : m_x(xVal), m_y(yVal)
    {
    }

    constexpr int xVal() const
    {
        return m_x;
    }

    constexpr int yVal() const
    {
        return m_y;
    }

    //Couldn't be constexpr
    void setX(int newX)
    {
        m_x = newX;
    }

    void setY(int newY)
    {
        m_y = newY;
    }

private:
    int m_x;
    int m_y;
};

constexpr Point midPoint(const Point& p1, const Point& p2)
{
    return Point{(p1.xVal() + p2.xVal()) / 2, 
                 (p1.yVal() + p2.yVal()) / 2 };
}

constexpr int pow(int base, int exp)
{
    return exp == 0 ? 1 : base * pow(base, exp - 1);
}

constexpr int pow14(int base, int exp) //C++14 only
{
    if(0 == exp)
        return 1;
    
    auto result = base;
    for(int i = 1; i < exp; ++ i)
        result *= base;

    return result;
}

int main()
{
    //constexpr function with compile-time arguments produce compile-time value
    constexpr int numCons = 5;
    std::array<int, pow(2, numCons)> arr;
    std::cout << "Size of the array: " << arr.size() << std::endl;

    std::array<int, pow14(2, numCons)> arr14;
    std::cout << "Size of the array14: " << arr14.size() << std::endl;

    //constexpr function with runtime argument produce runtime value
    int x = 4;
    int y = pow(3, x);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    
    //constexpr constructor and constexpr member function would be invoked in compile time
    constexpr Point p1(110, 112);
    constexpr Point p2(220, 222);
    constexpr Point p3 = midPoint(p1, p2);

    return 0;
}
