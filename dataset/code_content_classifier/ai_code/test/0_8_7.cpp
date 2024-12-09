#include <iostream>
#include <vector>
#include <string>

int countChanges(const std::string& a, const std::string& b, int k) {
    int changes = 0;
    for (int i = 0; i < b.length(); i++) {
        if (a[i] != b[i]) {
            changes++;
        }
    }
    for (int i = b.length(); i < a.length(); i++) {
        if (i >= k && a[i - k] != b[0]) {
            changes--;
        }
        if (i < a.length() - k && a[i] != b[m - 1]) {
            changes++;
        }
    }
    return changes;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::string a, b;
    std::cin >> a >> b;
    
    for (int k = 0; k <= n - m + 1; k++) {
        int changes = countChanges(a, b, k);
        std::cout << changes << " ";
    }
    
    std::cout << std::endl;
    
    return 0;
}