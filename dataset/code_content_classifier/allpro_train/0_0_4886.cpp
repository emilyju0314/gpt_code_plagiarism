#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll x;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB(int n, int d, std::vector<int>& a, std::vector<int>& b) {
    a.resize(n);
    b.resize(n);
    
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    
    for (int i = 0; i < n; i++) {
        std::swap(a[i], a[getNextX() % (i + 1)]);
    }
    
    for (int i = 0; i < n; i++) {
        if (i < d) {
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main() {
    int n, d;
    std::cin >> n >> d >> x;

    std::vector<int> a, b;
    initAB(n, d, a, b);

    std::vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int max_val = 0;
        for (int j = 0; j <= i; j++) {
            max_val = std::max(max_val, a[j] * b[i - j]);
        }
        c[i] = max_val;
    }

    for (int i = 0; i < n; i++) {
        std::cout << c[i] - 1 << std::endl;
    }

    return 0;
}