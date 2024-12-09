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
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum += a[i];
        }

        double k = static_cast<double>(sum) / n;

        int count = 0;
        std::vector<int> numEqualToK;
        for(int i = 0; i < n; i++) {
            if((sum - a[i]) % (n-1) == 0 && static_cast<double>((sum - a[i]) / (n-1)) == k) {
                numEqualToK.push_back(i);
            }
        }

        for(int i = 0; i < numEqualToK.size(); i++) {
            count += i * (numEqualToK.size() - i);
        }

        std::cout << count << std::endl;
    }

    return 0;
}