#include <iostream>
#include <vector>
#include <algorithm>

bool is_divisor(int x, int y) {
    return x % y == 0 && x != y;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }

    std::vector<int> S;
    std::vector<bool> used(N, false);

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            S.push_back(i+1);
            int current = X[i];

            for (int j = 0; j < N; j++) {
                if (!used[j] && is_divisor(X[j], current)) {
                    used[j] = true;
                }
            }
        }
    }

    std::cout << S.size() << std::endl;
    for (int i = 0; i < S.size(); i++) {
        std::cout << S[i] << " ";
    }

    return 0;
}