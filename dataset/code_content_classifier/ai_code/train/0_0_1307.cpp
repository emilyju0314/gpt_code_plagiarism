#include <iostream>
#include <algorithm>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    int team1 = std::min(a + b, c + d);
    int team2 = std::max(a + b, c + d);
    
    int diff = std::abs(team1 - team2);
    
    std::cout << diff << std::endl;
    
    return 0;
}