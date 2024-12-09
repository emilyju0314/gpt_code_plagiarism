#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, l, r;
    std::cin >> n >> l >> r;

    std::vector<int> a(n), p(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    std::vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = l + p[i] - 1;
    }

    std::sort(b.begin(), b.end());

    bool valid = true;
    for(int i = 0; i < n; i++) {
        if(a[i] + b[i] != p[i] + l - 1) {
            valid = false;
            break;
        }
    }

    if(valid) {
        for(int i = 0; i < n; i++) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}