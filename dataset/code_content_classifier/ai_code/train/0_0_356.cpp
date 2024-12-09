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

        std::vector<bool> visited(n, false);
        bool unique = true;
        for(int k = 0; k < n; k++) {
            int new_room = (k + a[k % n] + n) % n;
            if(visited[new_room]) {
                unique = false;
                break;
            }
            visited[new_room] = true;
        }

        if(unique) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}