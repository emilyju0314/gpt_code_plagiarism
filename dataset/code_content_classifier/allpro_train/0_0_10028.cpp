#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    long long num_down_cards = 2 * (N + M - 2);
    
    std::cout << num_down_cards << std::endl;

    return 0;
}