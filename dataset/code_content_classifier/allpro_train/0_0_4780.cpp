#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for(int i=0; i<n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> sorted_a = a;
        std::sort(sorted_a.begin(), sorted_a.end());

        int cnt1 = 0, cnt2 = 0;
        int left = 0, right = n-1;

        while(a[left] == sorted_a[left] && left < n) {
            left++;
            cnt1++;
        }

        while(a[right] == sorted_a[right] && right >= 0) {
            right--;
            cnt2++;
        }

        int ans = std::max(0, n-cnt1-cnt2);
        std::cout << ans << std::endl;
    }

    return 0;
}