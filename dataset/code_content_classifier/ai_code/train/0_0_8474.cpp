#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> data(N);
    for(int i = 0; i < N; i++) {
        int x, r;
        std::cin >> x >> r;
        data[i] = std::make_pair(x, r);
    }

    double left = 0, right = 1e6;
    for(int i = 0; i < 100; i++) {
        double mid = (left + right) / 2.0;
        bool valid = true;

        for(int j = 0; j < N; j++) {
            double dist = std::abs(mid - data[j].first);
            if(dist > data[j].second) {
                valid = false;
                break;
            }
        }

        if(valid) {
            right = mid;
        } else {
            left = mid;
        }
    }

    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << right << std::endl;

    return 0;
}