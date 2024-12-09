#include <iostream>
#include <algorithm>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    int sticks[4] = {a, b, c, d};
    std::sort(sticks, sticks + 4);
    
    if (sticks[0] + sticks[1] > sticks[2] || sticks[1] + sticks[2] > sticks[3]) {
        std::cout << "TRIANGLE" << std::endl;
    } else if (sticks[0] + sticks[1] == sticks[2] || sticks[1] + sticks[2] == sticks[3]) {
        std::cout << "SEGMENT" << std::endl;
    } else {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
    
    return 0;
}