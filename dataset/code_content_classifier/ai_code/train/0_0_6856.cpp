#include <iostream>
#include <vector>
#include <unordered_set>

int find_minimal_k(std::vector<int>& S) {
    int k = 1;
    std::unordered_set<int> new_set;

    while (true) {
        new_set.clear();
        for (int s : S) {
            new_set.insert(s ^ k);
        }

        if (new_set == std::unordered_set<int>(S.begin(), S.end())) {
            return k;
        }

        k++;
    }

    return -1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> S(n);
        for (int i = 0; i < n; i++) {
            std::cin >> S[i];
        }

        int minimal_k = find_minimal_k(S);
        std::cout << minimal_k << std::endl;
    }

    return 0;
}