#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        std::cin >> numbers[i];
    }

    int pair1, pair2;
    pair1 = numbers[0];
    pair2 = numbers[N - 1];

    std::cout << pair1 << " " << pair2 << std::endl;

    return 0;
}