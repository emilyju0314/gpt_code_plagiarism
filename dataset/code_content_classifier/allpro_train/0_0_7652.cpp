#include <iostream>
#include <vector>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> l(m), r(m), d(m);
    for (int i = 0; i < m; i++) {
        std::cin >> l[i] >> r[i] >> d[i];
    }

    std::vector<int> queries(k);
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        queries[i] = y;
    }

    std::vector<int> diff(m + 1);
    for (int i = 0; i < k; i++) {
        diff[queries[i]]++;
    }

    for (int i = 0; i < m; i++) {
        diff[i + 1] += diff[i];
    }

    for (int i = 0; i < m; i++) {
        a[l[i] - 1] += diff[i] * d[i];
        a[r[i]] -= diff[i] * d[i];
    }

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}