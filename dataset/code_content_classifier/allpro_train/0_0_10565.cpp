#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;
    
    std::vector<std::pair<int, int>> pairs(N);
    for(int i = 0; i < N; i++) {
        std::cin >> pairs[i].first >> pairs[i].second;
    }

    int count = 0;
    for(int i = 0; i < N; i++) {
        int diff = std::abs(pairs[i].first - pairs[i].second);
        if(diff <= A || (B <= diff && diff <= 2*A)) {
            count++;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int diff_sum = std::abs(pairs[i].first + pairs[j].first - pairs[i].second - pairs[j].second);
            if(diff_sum <= A || (B <= diff_sum && diff_sum <= 2*A)) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}