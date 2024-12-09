#include <iostream>
#include <vector>
#include <string>

int occur(const std::string& t, const std::string& s) {
    int count = 0;
    size_t nPos = s.find(t, 0);
    while (nPos != std::string::npos) {
        count++;
        nPos = s.find(t, nPos + 1);
    }
    return count;
}

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::string> friends(n);
    for (int i = 0; i < n; i++) {
        std::cin >> friends[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r, k;
        std::cin >> l >> r >> k;
        l--; // Adjusting for 0-based indexing

        int candies = 0;
        for (int j = l; j < r; j++) {
            candies += occur(friends[k-1], friends[j]);
        }

        std::cout << candies << std::endl;
    }

    return 0;
}