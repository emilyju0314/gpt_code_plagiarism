#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> t(n);
    for(int i = 0; i < n; i++) {
        std::cin >> t[i];
    }
    
    std::vector<std::pair<int, int>> diff;
    for(int i = 0; i < n; i++) {
        diff.push_back({a[i], t[i]});
    }
    
    std::sort(diff.begin(), diff.end());
    
    long long ans = 0;
    for(int i = 1; i < n; i++) {
        if(diff[i].first <= diff[i-1].first) {
            ans += (diff[i-1].first - diff[i].first + 1) * diff[i].second;
            diff[i].first = diff[i-1].first + 1;
        }
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}