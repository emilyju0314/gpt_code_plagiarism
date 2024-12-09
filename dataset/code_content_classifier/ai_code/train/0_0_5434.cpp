#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> colors(N);
    for(int i = 0; i < N; i++) {
        std::cin >> colors[i];
    }
    
    // Check if the total number of colors is odd or even
    int totalColors = 0;
    for(int i = 0; i < N; i++) {
        totalColors += colors[i] % 2;
    }
    
    if(totalColors % 2 == 0) {
        std::cout << "second" << std::endl;
    } else {
        std::cout << "first" << std::endl;
    }
    
    return 0;
}