#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::set<int> pockets;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        pockets.insert(a);
    }

    std::vector<int> answers;
    for (int i = 0; i < m; i++) {
        int x, k;
        std::cin >> x >> k;

        int j = 0;
        while (k > 0) {
            if (pockets.count(j) == 0) {
                k--;
            }
            j++;
        }

        answers.push_back(j - 1);
    }

    for (int ans : answers) {
        std::cout << ans << std::endl;
    }

    return 0;
}