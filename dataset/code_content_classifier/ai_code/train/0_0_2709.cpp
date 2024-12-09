#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

const int MOD = 998244353;

bool is_latin_square(const std::vector<std::vector<int>>& arrays) {
    int n = arrays.size() / 2;
    for (int k = 1; k <= n; ++k) {
        std::set<int> elements;
        for (int i = 0; i < n; ++i) {
            elements.insert(arrays[i][k-1]);
        }
        if (elements.size() != n) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> arrays(n * 2, std::vector<int>(n));
        for (int i = 0; i < n * 2; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> arrays[i][j];
            }
        }

        std::vector<int> good_subset;
        for (int k = 0; k < (1 << (n * 2)); ++k) {
            std::vector<std::vector<int>> candidate_arrays;
            for (int i = 0; i < n * 2; ++i) {
                if ((k & (1 << i)) != 0) {
                    candidate_arrays.push_back(arrays[i]);
                }
            }
            if (candidate_arrays.size() == n && is_latin_square(candidate_arrays)) {
                good_subset = candidate_arrays.front();
                break;
            }
        }

        long long good_subsets = 1;
        for (int i = 0; i < n; ++i) {
            good_subsets = (good_subsets * n) % MOD;
        }

        std::cout << good_subsets << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cout << (std::find(arrays.begin(), arrays.end(), good_subset) - arrays.begin()) + 1 << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}