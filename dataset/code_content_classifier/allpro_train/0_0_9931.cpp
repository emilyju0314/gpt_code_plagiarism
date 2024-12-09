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

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int operations = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 1) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] != 1) {
                    int g = gcd(arr[i], arr[j]);
                    if (g == 1) {
                        operations += (j - i);
                        arr[i] = 1;
                        break;
                    }
                }
            }
            if (arr[i] != 1) {
                std::cout << "-1" << std::endl;
                return 0;
            }
        }
    }

    std::cout << operations << std::endl;

    return 0;
}