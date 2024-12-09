#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        std::vector<int> colors(n, -1);
        int color = 1;

        for (int i = 0; i < n; i++) {
            if (colors[i] != -1) continue;

            colors[i] = color;
            for (int j = i + 1; j < n; j++) {
                if (colors[j] == -1 && gcd(arr[i], arr[j]) > 1) {
                    colors[j] = color;
                }
            }

            color++;
        }

        std::cout << color - 1 << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << colors[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}