#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int bal = 0;
    std::vector<int> close(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') bal++;
        else bal--;
        close[i] = bal;
    }

    int ans = 0, l = 1, r = 1;
    for (int i = 0; i < n; i++) {
        if (close[i] > ans) {
            ans = close[i];
            l = r = i + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int j = i - close[i];
        if (j < n && close[j] == 0 && close[i] > close[r-1] - 2) {
            ans = close[i];
            l = j + 1;
            r = i + 1;
        }
    }

    std::cout << ans << "\n";
    std::cout << l << " " << r << "\n";

    return 0;
}