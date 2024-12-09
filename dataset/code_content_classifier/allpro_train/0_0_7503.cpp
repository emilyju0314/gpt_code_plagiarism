#include <iostream>
#include <vector>
#include <set>

int main() {
    int m;
    std::cin >> m;

    std::vector<std::set<int>> acquaintances(5);

    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;

        acquaintances[a-1].insert(b);
        acquaintances[b-1].insert(a);
    }

    bool win = false;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (acquaintances[i].count(j+1)) {
                for (int k = j + 1; k < 5; k++) {
                    if (acquaintances[j].count(k+1) && acquaintances[i].count(k+1)) {
                        std::cout << "WIN" << std::endl;
                        return 0;
                    } else if (!acquaintances[j].count(k+1) && !acquaintances[i].count(k+1)) {
                        std::cout << "WIN" << std::endl;
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << "FAIL" << std::endl;

    return 0;
}