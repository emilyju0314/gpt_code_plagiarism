#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        int uniqueIndex;

        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            if(i > 0 && a[i] != a[i-1]) {
                if(i > 1 && a[i] == a[i-2]) {
                    uniqueIndex = i-1;
                } else {
                    uniqueIndex = i;
                }
            }
        }

        std::cout << uniqueIndex + 1 << std::endl;
    }

    return 0;
}