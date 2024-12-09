#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::sort(b.begin(), b.end());

    int diff1 = b[1] - b[0];
    int diff2 = b[n-1] - b[n-2];

    int index = -1;

    if (diff1 == diff2) {
        int diff = diff1;
        for (int i = 2; i < n; i++) {
            if (b[i] - b[i-1] != diff) {
                index = i;
                break;
            }
        }
    } else {
        if (n > 2) {
            if (b[2] - b[0] == b[n-1] - b[1]) {
                index = 1;
            } else if (b[n-1] - b[n-3] == b[2] - b[0]) {
                index = n;
            }
        }
    }

    std::cout << index << std::endl;

    return 0;
}