#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>

int main()
{
    std::vector<int> vec(10);
    std::iota(vec.begin(), vec.end(), 1);

    int sum = std::accumulate(vec.begin(), vec.end(), 0);

    int product = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());

    std::string str = std::accumulate(vec.begin(), vec.end(), std::string{},
		                      [](const std::string& a, int b)
                                      {
                                          return a.empty() ? std::to_string(b)
                                                 : a + "-" + std::to_string(b);
                                      });

    std::cout << "sum: " << sum << std::endl
              << "product: " << product << std::endl
              << "dash-separated string: " << str << std::endl;

    return 0;
}
