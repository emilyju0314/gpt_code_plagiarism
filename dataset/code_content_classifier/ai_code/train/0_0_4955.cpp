#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        
        std::vector<int> a(n);
        std::vector<int> freq(n + 1);

        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            freq[a[i]]++;
        }

        int minIndex = -1;
        int minValue = n + 1;

        for (int i = 0; i < n; i++) {
            if (freq[a[i]] == 1 && a[i] < minValue) {
                minValue = a[i];
                minIndex = i;
            }
        }

        std::cout << (minIndex != -1 ? minIndex + 1 : -1) << std::endl;
    }

    return 0;
}