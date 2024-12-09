#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        char s;
        int x;
        std::cin >> s >> x;

        if (s == '>') {
            for (int j = 0; j < n; j++) {
                if (a[j] > x) {
                    a[j] = -a[j];
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                if (a[j] < x) {
                    a[j] = -a[j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}