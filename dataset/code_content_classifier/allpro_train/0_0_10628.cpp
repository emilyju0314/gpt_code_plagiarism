#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    int count = 0;
    for (int i = 1; i <= N / 2; i++) {
        if (N - i != i) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}