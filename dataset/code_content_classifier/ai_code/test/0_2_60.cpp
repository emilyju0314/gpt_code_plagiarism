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
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
        }

        int count = 0;
        int pairs = 0;
        double k = double(sum) / double(n);
        for(int i = 0; i < n; i++) {
            if(a[i] == k) {
                count++;
                pairs += count - 1;
            }
        }

        std::cout << pairs << std::endl;
    }

    return 0;
}