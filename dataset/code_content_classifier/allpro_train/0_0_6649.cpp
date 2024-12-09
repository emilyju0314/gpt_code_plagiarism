#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long n, m, q;
    std::cin >> n >> m >> q;

    std::vector<int> calendar(m, 0);
    for (int i = 0; i < q; ++i) {
        int a;
        std::cin >> a;
        calendar[a] = 1;
    }

    int connected_parts = 0;
    for (int i = 0; i < m; ++i) {
        if (calendar[i] == 1) {
            connected_parts++;
            int j = i;
            while (j < m && calendar[j] == 1) {
                j++;
            }
            i = j - 1;
        }
    }

    std::cout << connected_parts << std::endl;

    return 0;
}