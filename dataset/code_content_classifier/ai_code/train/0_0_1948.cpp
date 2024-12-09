#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cities[i];
    }

    for (int i = 0; i < n; i++) {
        int mini, maxi;

        if (i == 0) {
            mini = abs(cities[i] - cities[i+1]);
            maxi = abs(cities[i] - cities[n-1]);
        } else if (i == n-1) {
            mini = abs(cities[i] - cities[i-1]);
            maxi = abs(cities[i] - cities[0]);
        } else {
            mini = std::min(abs(cities[i] - cities[i-1]), abs(cities[i] - cities[i+1]));
            maxi = std::max(abs(cities[i] - cities[0]), abs(cities[i] - cities[n-1]));
        }

        std::cout << mini << " " << maxi << std::endl;
    }

    return 0;
}