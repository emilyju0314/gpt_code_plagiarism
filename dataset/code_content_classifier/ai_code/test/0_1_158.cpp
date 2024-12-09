#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> x[i];
        }

        std::vector<std::string> answers(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> answers[i];
        }

        std::vector<int> p(m);
        for (int i = 0; i < m; ++i) {
            p[i] = i + 1;
        }

        std::sort(p.begin(), p.end());

        do {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                int points = 0;
                for (int j = 0; j < m; ++j) {
                    if (answers[i][j] == '1') {
                        points += p[j];
                    }
                }
                sum += abs(x[i] - points);
            }

            if (sum > 0) {
                for (int i = 0; i < m; ++i) {
                    std::cout << p[i] << " ";
                }
                std::cout << std::endl;
                break;
            }
        } while (std::next_permutation(p.begin(), p.end()));
    }

    return 0;
}