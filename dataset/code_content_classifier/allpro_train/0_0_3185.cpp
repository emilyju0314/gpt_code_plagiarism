#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> nums(N);
    for(int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }

    int g = nums[0];
    for(int i = 1; i < N; i++) {
        g = gcd(g, nums[i]);
    }

    int max_num = *std::max_element(nums.begin(), nums.end());

    int takahashi_moves = (max_num - N) / g;

    if(takahashi_moves % 2 == 1) {
        std::cout << "First" << std::endl;
    } else {
        std::cout << "Second" << std::endl;
    }

    return 0;
}