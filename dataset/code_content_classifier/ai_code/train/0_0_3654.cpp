#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> necklace(n);
        std::vector<int> bracelet(n);

        for(int i = 0; i < n; i++) {
            std::cin >> necklace[i];
        }

        for(int i = 0; i < n; i++) {
            std::cin >> bracelet[i];
        }

        std::sort(necklace.begin(), necklace.end());
        std::sort(bracelet.begin(), bracelet.end());

        for(int i = 0; i < n; i++) {
            std::cout << necklace[i] << " ";
        }
        std::cout << std::endl;

        for(int i = 0; i < n; i++) {
            std::cout << bracelet[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}