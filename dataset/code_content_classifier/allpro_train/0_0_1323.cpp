#include <iostream>
#include <vector>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> imperfections(n - 1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (i != j) {
                int curr_gcd = gcd(i, j);
                imperfections[j - 2] = std::max(imperfections[j - 2], curr_gcd);
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        std::cout << imperfections[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}