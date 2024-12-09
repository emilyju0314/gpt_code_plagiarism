#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> camels(n);

    for (int i = 0; i < n; i++) {
        int x, d;
        std::cin >> x >> d;
        camels[i] = std::make_pair(x, d);
    }

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && camels[i].first + camels[i].second == camels[j].first && camels[j].first + camels[j].second == camels[i].first) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}