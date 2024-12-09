#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> residents(n+m), is_taxi(n+m);
    for(int i = 0; i < n+m; i++) {
        std::cin >> residents[i];
    }

    for(int i = 0; i < n+m; i++) {
        std::cin >> is_taxi[i];
    }

    std::vector<int> taxi_coords;
    for(int i = 0; i < n+m; i++) {
        if(is_taxi[i] == 1) {
            taxi_coords.push_back(residents[i]);
        }
    }

    std::sort(taxi_coords.begin(), taxi_coords.end());

    std::vector<int> result(m, 0);
    for(int i = 0; i < n+m; i++) {
        if(is_taxi[i] == 0) {
            int closest_taxi_idx = 0;
            int min_dist = abs(residents[i] - taxi_coords[0]);
            for(int j = 1; j < taxi_coords.size(); j++) {
                if(abs(residents[i] - taxi_coords[j]) < min_dist) {
                    closest_taxi_idx = j;
                    min_dist = abs(residents[i] - taxi_coords[j]);
                }
            }
            result[closest_taxi_idx]++;
        }
    }

    for(int i = 0; i < m; i++) {
        std::cout << result[i] << " ";
    }

    return 0;
}