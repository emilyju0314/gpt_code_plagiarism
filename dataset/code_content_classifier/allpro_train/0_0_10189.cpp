#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string colors;
    std::cin >> colors;

    std::vector<int> freq(26, 0);
    for (char color : colors) {
        freq[color - 'a']++;
    }

    bool canDistribute = true;
    for (int num : freq) {
        if (num > k) {
            canDistribute = false;
            break;
        }
    }

    if (canDistribute) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}