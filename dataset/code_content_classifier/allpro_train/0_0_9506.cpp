#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(N, 0);
    for (int i = 0; i < N; i++) {
        b[i] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::vector<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans[i] = b[i];
    }

    for (int i = 0; i < N; i++) {
        if (i == 0 || b[i-1] != a[i]) {
            ans[i] = b[i];
        } else {
            while (b[i] == a[i] || b[i] == a[i-1]) {
                std::next_permutation(b.begin(), b.end());
            }
            ans[i] = b[i];
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}