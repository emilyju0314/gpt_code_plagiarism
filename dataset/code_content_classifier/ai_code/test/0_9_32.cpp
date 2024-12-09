#include <iostream>
#include <vector>

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

        int max_k = 1;
        int cur_sum = a[0];
        int min_val = a[0];
        
        for(int i = 1; i < n; i++) {
            if(a[i] < min_val) {
                max_k++;
            }
            min_val = std::min(min_val, a[i]);
        }

        std::cout << max_k << std::endl;
    }

    return 0;
}