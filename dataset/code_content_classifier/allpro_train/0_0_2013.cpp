#include <iostream>
#include <vector>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        std::vector<int> energies(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> energies[i];
        }

        for (int i = 0; i < n; ++i) {
            if (energies[i] % 2 == 0) {
                for (int j = 0; j < n; ++j) {
                    if (energies[j] % 2 != 0) {
                        std::cout << energies[j] << " ";
                    } else {
                        std::cout << -energies[j] << " ";
                    }
                }
                std::cout << "\n";
                break;
            }
        }
    }

    return 0;
}