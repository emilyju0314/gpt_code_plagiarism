#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int A, B, n;
        std::cin >> A >> B >> n;

        std::vector<int> attackPowers(n);
        std::vector<int> healthValues(n);

        for(int i = 0; i < n; i++) {
            std::cin >> attackPowers[i];
        }

        for(int i = 0; i < n; i++) {
            std::cin >> healthValues[i];
        }

        std::vector<std::pair<int, int>> monsters(n);

        for(int i = 0; i < n; i++) {
            monsters[i] = {attackPowers[i], healthValues[i]};
        }

        std::sort(monsters.begin(), monsters.end());

        bool canKill = true;

        for(int i = 0; i < n; i++) {
            int fightsNeeded = (monsters[i].second + A - 1) / A;
            B -= fightsNeeded * monsters[i].first;

            if(i == n-1 && B <= 0) {
                canKill = false;
            }
        }

        if(canKill) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}