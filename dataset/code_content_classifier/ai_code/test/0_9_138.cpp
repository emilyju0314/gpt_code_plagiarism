#include <iostream>
#include <vector>
#include <algorithm>

long long getMaxTotalCost(std::vector<int>& a, std::vector<int>& b, int k) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int j = 0;
    long long totalCost = 0;

    for (int i = 0; i < a.size(); i++) {
        while (j < b.size() && b[j] <= a[i] + k) {
            j++;
        }

        if (j < b.size()) {
            totalCost += b[j];
            j++;
        }
    }

    return totalCost;
}

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<int> a(n);
    std::vector<int> b(m);
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
        int k;
        std::cin >> k;
        std::cout << getMaxTotalCost(a, b, k) << std::endl;
    }

    return 0;
}