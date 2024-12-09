#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::string> cities(n);
        for (int i = 0; i < n; i++) {
            std::cin >> cities[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    std::string tmp = cities[i] + cities[j];
                    for (int k = 0; k < cities[i].size(); k++) {
                        if (cities[j].rfind(tmp.substr(k)) == 0) {
                            tmp = cities[i] + cities[j].substr(tmp.size() - k);
                            break;
                        }
                    }
                    ans = std::max(ans, (int)tmp.size());
                }
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}