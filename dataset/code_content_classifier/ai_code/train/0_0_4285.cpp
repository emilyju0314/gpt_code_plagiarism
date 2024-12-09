#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> station_numbers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> station_numbers[i];
    }

    bool unique = true;
    int next_station;

    for (int i = 1; i < n; i++) {
        if (station_numbers[i] - station_numbers[i-1] != 1) {
            if (unique) {
                unique = false;
                next_station = station_numbers[i-1] + 1;
            } else {
                std::cout << "not unique" << std::endl;
                return 0;
            }
        }
    }

    if (unique) {
        std::cout << "unique" << std::endl;
        std::cout << station_numbers[n-1] + 1 << std::endl;
    } else {
        std::cout << "not unique" << std::endl;
    }

    return 0;
}