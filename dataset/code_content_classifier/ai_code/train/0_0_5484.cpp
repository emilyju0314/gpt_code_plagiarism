#include <iostream>
#include <vector>

int main() {
    int m, k;
    std::cin >> m >> k;

    std::vector<int> distances(m);
    for(int i=0; i<m; i++) {
        std::cin >> distances[i];
    }

    std::vector<int> supplies(m);
    for(int i=0; i<m; i++) {
        std::cin >> supplies[i];
    }

    int total_time = 0;
    for(int i=0; i<m; i++) {
        total_time += distances[i]; // time to travel the distance
        if(i < m-1) {
            if(total_time % k != 0) {
                total_time += k - (total_time % k); // wait until the supply refreshes
            }
            if(total_time % k == 0) {
                total_time += std::max(0, supplies[i] - (total_time / k)); // refill the fuel tank
            }
        }
    }

    std::cout << total_time << std::endl;

    return 0;
}