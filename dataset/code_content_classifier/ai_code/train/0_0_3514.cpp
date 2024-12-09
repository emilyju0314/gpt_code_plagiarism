#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> even, odd;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }

    if (even.size() != n / 2 || odd.size() != n / 2) {
        std::cout << -1 << std::endl;
    } else {
        int numExchanges = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && a[i] % 2 != 0) {
                for (int j = 1; j <= m; j++) {
                    if (std::find(a.begin(), a.end(), j) == a.end()) {
                        a[i] = j;
                        numExchanges++;
                        break;
                    }
                }
            } else if (i % 2 == 1 && a[i] % 2 == 0) {
                for (int j = 1; j <= m; j++) {
                    if (std::find(a.begin(), a.end(), j) == a.end()) {
                        a[i] = j;
                        numExchanges++;
                        break;
                    }
                }
            }
        }

        std::cout << numExchanges << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}