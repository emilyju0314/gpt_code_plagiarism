#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::string directions;
    std::cin >> directions;
    
    std::vector<int> jumpLengths(n);
    for (int i = 0; i < n; i++) {
        std::cin >> jumpLengths[i];
    }
    
    int currentCell = 0;
    while (currentCell >= 0 && currentCell < n) {
        if (directions[currentCell] == '>') {
            currentCell += jumpLengths[currentCell];
        } else {
            currentCell -= jumpLengths[currentCell];
        }
    }
    
    if (currentCell < 0 || currentCell >= n) {
        std::cout << "FINITE" << std::endl;
    } else {
        std::cout << "INFINITE" << std::endl;
    }
    
    return 0;
}