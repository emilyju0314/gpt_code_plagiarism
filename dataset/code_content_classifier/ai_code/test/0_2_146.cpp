#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> p(n+1);
    for(int i = 1; i <= n; i++) {
        std::cin >> p[i];
    }

    for(int i = 0; i < q; i++) {
        int t, x, y;
        std::cin >> t >> x >> y;

        if(t == 1) {
            std::swap(p[x], p[y]);
        } else if(t == 2) {
            int count = 0;
            int current = x;
            while(count < y) {
                current = p[current];
                count++;
            }
            std::cout << current << std::endl;
        }
    }

    return 0;
}