#include <iostream>
#include <vector>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> colors(n);
    for(int i = 0; i < n; i++) {
        std::cin >> colors[i];
    }

    int cost = 0;
    for(int i = 0; i < n/2; i++) {
        if(colors[i] == 2 && colors[n-1-i] == 2) {
            cost += std::min(a, b);
        } else if(colors[i] == 2) {
            cost += (colors[n-1-i] == 0) ? a : b;
        } else if(colors[n-1-i] == 2) {
            cost += (colors[i] == 0) ? a : b;
        } else if(colors[i] != colors[n-1-i]) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::cout << cost << std::endl;

    return 0;
}