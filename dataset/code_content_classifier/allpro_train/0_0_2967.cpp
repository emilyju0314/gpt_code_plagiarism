#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        int max_dist = -1;
        for(int l = i, r = i; l >= 0 && r < n; l--, r++) {
            std::vector<int> temp(a.begin() + l, a.begin() + r + 1);
            std::sort(temp.begin(), temp.end());
            int center = (l + r) / 2;
            int dist = std::abs(center - i);
            max_dist = std::max(max_dist, dist);
        }
        std::cout << max_dist << " ";
    }

    return 0;
}