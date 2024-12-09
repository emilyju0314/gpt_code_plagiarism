#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        int diff = 0;
        bool possible = true;
        int push_l = -1, push_r = -1, push_k = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                int curr_diff = b[i] - a[i];
                if (push_l != -1 && i != push_r) {
                    possible = false;
                    break;
                } else if (push_l != -1 && i == push_r && curr_diff != push_k) {
                    possible = false;
                    break;
                } else if (curr_diff > diff) {
                    possible = false;
                    break;
                } else if (a[i] == b[i]) {
                    push_l = -1;
                } else {
                    push_l = i;
                    push_r = i;
                    push_k = curr_diff;
                }
                diff = curr_diff;
            } else if (a[i] > b[i]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}