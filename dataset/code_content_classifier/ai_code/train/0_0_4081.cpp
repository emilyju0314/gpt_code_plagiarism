#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> colors;
    for (int i = 0; i < n; i++) {
        bool painted = false;
        for (int j = 0; j < colors.size(); j++) {
            if (a[i] % colors[j] == 0 || colors[j] % a[i] == 0) {
                painted = true;
                colors[j] = gcd(colors[j], a[i]);
                break;
            }
        }

        if (!painted) {
            colors.push_back(a[i]);
        }
    }

    std::cout << colors.size() << std::endl;

    return 0;
}