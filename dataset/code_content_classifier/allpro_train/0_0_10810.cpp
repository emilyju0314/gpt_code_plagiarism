#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<long long> piles(N);
    for(int i = 0; i < N; i++) {
        std::cin >> piles[i];
    }

    std::sort(piles.rbegin(), piles.rend());

    long long sum = 0;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            sum += piles[i];
        } else {
            sum -= piles[i];
        }
    }

    if(sum > 0) {
        std::cout << "First" << std::endl;
    } else {
        std::cout << "Second" << std::endl;
    }

    return 0;
}