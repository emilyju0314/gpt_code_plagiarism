#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int k;
        std::string m;
        std::cin >> k >> m;

        if (k > m.size() && s.find(m) != std::string::npos) {
            int count = 0;
            int min_len = s.size() + 1;
            
            for (int j = 0; j <= s.size() - m.size(); ++j) {
                if (s.substr(j, m.size()) == m) {
                    count++;
                    if (count == k) {
                        min_len = std::min(min_len, j + (int)m.size());
                    }
                }
            }

            if (count < k) {
                std::cout << -1 << std::endl;
            } else {
                std::cout << min_len << std::endl;
            }
        } else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}