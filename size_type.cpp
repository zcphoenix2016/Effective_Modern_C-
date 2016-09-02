#include <vector>
#include <iostream>

struct Foo
{
    int m_i;  
};

int main()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::vector<int>::size_type size = vec.size();
    std::cout << size << std::endl;
    
    std::vector<Foo>::value_type f{200};
    std::cout << f.m_i << std::endl;
    
    const std::size_t N = 10;
    int* a = new int[N];
 
    for (std::size_t n = 0; n < N; ++n)
    {
        a[n] = n;
    }	
        
    for (std::size_t n = N; n-- > 0;) // Reverse cycles are tricky for unsigned types.
    {
        std::cout << a[n] << " ";
    }
    std::cout << std::endl;
 
    delete[] a;
    
    return 0;
}
