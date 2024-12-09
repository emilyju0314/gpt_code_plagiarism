#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> p(n);
        for(int i = 0; i < n; i++) {
            std::cin >> p[i];
        }

        std::vector<int> a(n);
        bool bipartite = true;

        for(int i = 0; i < n; i++) {
            if(i + 1 < p[i]) {
                a[i] = p[i];
            } else {
                a[i] = -p[i];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(p[i] < p[j] != a[i] > a[j]) {
                    bipartite = false;
                    break;
                }
            }
            if(!bipartite) {
                break;
            }
        }

        if(bipartite) {
            std::cout << "YES\n";
            for(int i = 0; i < n; i++) {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}