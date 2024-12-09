#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cards[i];
    }

    std::sort(cards.begin(), cards.end());

    std::vector<int> ans(n+1, 0);
    int current = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        if (cards[i] == cnt) {
            current++;
        } else {
            ans[current]++;
            cnt++;
            i--;
        }
    }
    ans[current]++;

    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << std::endl;
    }

    return 0;
}