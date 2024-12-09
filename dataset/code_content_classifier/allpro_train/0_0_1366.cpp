#include <iostream>
#include <vector>

int popcount(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int f(int n) {
    int count = 0;
    while (n > 0) {
        n %= popcount(n);
        count++;
    }
    return count;
}

int main() {
    int N;
    std::string X;
    
    std::cin >> N >> X;

    std::vector<int> results;
    for (int i = 0; i < N; i++) {
        int xi = stoi(X);
        xi ^= 1 << (N - i - 1);
        results.push_back(f(xi));
    }

    for (int res : results) {
        std::cout << res << std::endl;
    }

    return 0;
}