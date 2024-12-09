#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::vector<int> b(m);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    // Sort array a
    std::sort(a.begin(), a.end());

    // For each element of array b, find the number of elements in array a that are less than or equal to it
    for (int i = 0; i < m; i++) {
        int count = std::upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        std::cout << count << " ";
    }

    return 0;
}