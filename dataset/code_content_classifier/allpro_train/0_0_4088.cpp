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

        for(int i = 0; i < n-1; i++) {
            if(a[i] > a[i+1]) {
                std::cout << "YES" << std::endl;
                goto end;
            }
        }

        std::cout << "NO" << std::endl;

        end: continue;
    }

    return 0;
}