#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for(int i = 0; i < k; i++) {
        std::vector<int> s(n);
        for(int j = 0; j < n; j++) {
            for(int l = 0; l <= j; l++) {
                s[j] += a[l];
                s[j] %= 1000000007; // take the remainder to avoid overflow
            }
        }
        a = s;
    }

    for(int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}