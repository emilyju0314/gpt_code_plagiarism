#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int pos1 = -1, pos2 = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            pos1 = i;
            pos2 = i + 1;
            break;
        }
    }

    if (pos1 != -1 && pos2 != -1) {
        std::cout << pos1 << " " << pos2 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}