#include <iostream>
#include <vector>
#include <algorithm>

struct Train {
    int departureTime;
    int arrivalTime;
    int fare;
};

int calculateMinFare(std::vector<std::vector<Train>>& trains, int g) {
    int maxClasses = 0;
    int minFare = INT_MAX;

    for (int i = 0; i < trains.size(); i++) {
        int classes = 0;
        int currentTime = 0;
        for (int j = 0; j < trains[i].size(); j++) {
            if (currentTime <= trains[i][j].departureTime) {
                classes++;
                currentTime = trains[i][j].arrivalTime;
                minFare = std::min(minFare, trains[i][j].fare);
            }
        }
        maxClasses = std::max(maxClasses, classes);
    }

    return maxClasses == g ? minFare : 0;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            int m;
            std::cin >> m;
            
            std::vector<std::vector<Train>> trains(m);
            for (int j = 0; j < m; j++) {
                int x, y, c;
                std::cin >> x >> y >> c;
                trains[j].push_back({x, y, c});
            }

            int g;
            std::cin >> g;

            int minFare = calculateMinFare(trains, g);
            if (minFare != 0) {
                std::cout << g << " " << minFare << std::endl;
            } else {
                std::cout << "0 0" << std::endl;
            }
        }
    }

    return 0;
}