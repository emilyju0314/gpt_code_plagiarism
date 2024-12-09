#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::unordered_map<int, long long> counts;
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int count = 0;
        while (x > 0) {
            if (counts.find(x) != counts.end()) {
                ans += counts[x];
                break;
            }
            if (x % 2 == 1) {
                count++;
            }
            x /= 2;
        }
        counts[a[i]] += count;
    }

    std::cout << ans << std::endl;

    return 0;
}