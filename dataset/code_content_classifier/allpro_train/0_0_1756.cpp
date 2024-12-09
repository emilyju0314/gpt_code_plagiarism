#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::map<int, int> freq;
        for(int i = 0; i < n; i++) {
            int num;
            std::cin >> num;
            freq[num]++;
        }

        int max_count = 0;
        for(auto it = freq.begin(); it != freq.end(); it++) {
            max_count = std::max(max_count, it->second);
        }

        int result = std::max(n - max_count, n % 2);
        std::cout << result << std::endl;
    }

    return 0;
}