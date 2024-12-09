Here is a C++ solution to find the minimum possible value of |x-y|:

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cards[i];
    }

    std::sort(cards.rbegin(), cards.rend());

    long long sum_one = 0;
    long long sum_two = 0;
    long long min_diff = 1e18;

    for (int i = 1; i < N; i++) {
        sum_one += cards[i - 1];
        sum_two = 0;
        for (int j = i; j < N; j++) {
            sum_two += cards[j];
        }

        min_diff = std::min(min_diff, abs(sum_one - sum_two));
    }

    std::cout << min_diff << std::endl;

    return 0;
}