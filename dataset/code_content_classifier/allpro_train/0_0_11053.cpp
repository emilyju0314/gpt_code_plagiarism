#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int LCP(const std::string& s1, const std::string& s2) {
    int i = 0;
    while (i < s1.length() && i < s2.length() && s1[i] == s2[i]) {
        i++;
    }
    return i;
}

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::string> strings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }

    for (int i = 0; i < q; i++) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int a, b;
            std::cin >> a >> b;

            int maxExpression = 0;
            for (int l = a - 1; l < b; l++) {
                for (int r = l; r < b; r++) {
                    int lcp = strings[l].size();
                    for (int k = l; k < r; k++) {
                        lcp = std::min(lcp, LCP(strings[k], strings[k + 1]));
                    }
                    maxExpression = std::max(maxExpression, lcp * (r - l + 1));
                }
            }
            std::cout << maxExpression << std::endl;
        } else if (type == 2) {
            int x;
            std::string y;
            std::cin >> x >> y;
            strings[x - 1] = y;
        }
    }

    return 0;
}