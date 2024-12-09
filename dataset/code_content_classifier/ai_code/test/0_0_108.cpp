#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        std::vector<int> b(n);

        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        std::vector<char> canWin(n, '0');

        int minStrengthA = *std::min_element(a.begin(), a.end());
        int minStrengthB = *std::min_element(b.begin(), b.end());

        std::unordered_set<int> minPlayersA, minPlayersB;

        for(int i = 0; i < n; i++) {
            if(a[i] == minStrengthA) {
                minPlayersA.insert(i);
            }
            if(b[i] == minStrengthB) {
                minPlayersB.insert(i);
            }
        }

        for(int i = 0; i < n; i++) {
            if(minPlayersA.find(i) == minPlayersA.end() && minPlayersB.find(i) == minPlayersB.end()) {
                canWin[i] = '1';
            }
        }

        for(int i = 0; i < n; i++) {
            std::cout << canWin[i];
        }
        std::cout << std::endl;
    }

    return 0;
}