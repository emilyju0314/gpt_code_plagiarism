#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> breads(N);
    for(int i = 0; i < N; i++) {
        std::cin >> breads[i];
    }

    int totalBreads = 0;
    for(int bread : breads) {
        totalBreads += bread;
    }

    int maxSandwiches = totalBreads / 2;
    
    std::cout << maxSandwiches << std::endl;

    return 0;
}