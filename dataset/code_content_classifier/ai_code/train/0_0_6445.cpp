#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> longest_inc_subseq(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                longest_inc_subseq[i] = std::max(longest_inc_subseq[i], longest_inc_subseq[j] + 1);
            }
        }
    }

    std::vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[longest_inc_subseq[i]]++;
    }

    std::vector<int> groups(n, 0);
    for (int i = 0; i < n; i++) {
        if (dp[longest_inc_subseq[i]] == 1) {
            groups[i] = 1;
        } else if (dp[longest_inc_subseq[i]] == longest_inc_subseq[i]) {
            groups[i] = 3;
        } else {
            groups[i] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << groups[i];
    }

    return 0;
}