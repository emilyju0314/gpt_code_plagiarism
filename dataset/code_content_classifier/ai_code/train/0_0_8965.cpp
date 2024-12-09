#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> left(n);
    std::vector<int> right(n);
    
    for (int i = 0; i < n; i++) {
        left[i] = i - 1;
        while (left[i] >= 0 && a[left[i]] <= a[i]) {
            left[i] = left[left[i]];
        }
    }
    
    for (int i = n - 1; i >= 0; i--) {
        right[i] = i + 1;
        while (right[i] < n && a[right[i]] <= a[i]) {
            right[i] = right[right[i]];
        }
    }
    
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        int l = i - left[i];
        int r = right[i] - i;
        total += (long long)a[i] * (l * r - l - r + 1);
    }
    
    std::cout << total << std::endl;
    
    return 0;
}