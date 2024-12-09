#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::vector<int> b(k);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
        std::cin >> b[i];
    }

    std::sort(b.begin(), b.end(), std::greater<int>());

    int zero_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zero_count++;
        }
    }

    bool possible = false;
    std::vector<int> temp_a = a;

    do {
        bool increasing = true;
        int b_index = 0;

        for (int i = 0; i < n; i++) {
            if (temp_a[i] == 0) {
                temp_a[i] = b[b_index++];
            }
        }

        for (int i = 1; i < n; i++) {
            if (temp_a[i] <= temp_a[i - 1]) {
                increasing = false;
                break;
            }
        }

        if (!increasing) {
            possible = true;
            break;
        }

        temp_a = a;
    } while(std::prev_permutation(b.begin(), b.end()));

    if(possible) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}