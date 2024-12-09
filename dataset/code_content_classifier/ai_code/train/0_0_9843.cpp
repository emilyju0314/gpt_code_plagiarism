#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cities[i];
    }

    std::sort(cities.begin(), cities.end());

    int min_distance = cities[1] - cities[0];
    int count = 1;

    for (int i = 2; i < n; i++) {
        int distance = cities[i] - cities[i-1];

        if (distance == min_distance) {
            count++;
        } else if (distance < min_distance) {
            min_distance = distance;
            count = 1;
        }
    }

    std::cout << min_distance << " " << count << std::endl;

    return 0;
}