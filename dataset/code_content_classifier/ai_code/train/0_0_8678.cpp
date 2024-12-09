#include <iostream>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i + j) % 2 == 0) {
                ans++;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}