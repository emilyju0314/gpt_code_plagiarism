#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Airport {
    double x, y;
};

struct Flight {
    int departure, arrival;
    double speed;
};

double calculateDistance(const Airport& a, const Airport& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double calculateTravelTime(const Airport& warp1, const Airport& warp2, const Airport& departure, const Airport& arrival, double speed) {
    double time1 = calculateDistance(departure, warp1) / speed;
    double time2 = calculateDistance(warp1, warp2) / speed;
    double time3 = calculateDistance(warp2, arrival) / speed;
    return time1 + time2 + time3;
}

double calculateAverageCost(const std::vector<Airport>& airports, const std::vector<Flight>& flights, const Airport& warp1, const Airport& warp2) {
    double sum = 0.0;
    
    for (const Flight& flight : flights) {
        const Airport& departure = airports[flight.departure - 1];
        const Airport& arrival = airports[flight.arrival - 1];
        
        double travelTime = calculateTravelTime(warp1, warp2, departure, arrival, flight.speed);
        
        sum += travelTime * travelTime;
    }
    
    return std::sqrt(sum / flights.size());
}

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) break;
        
        std::vector<Airport> airports(n);
        std::vector<Flight> flights(m);
        
        for (int i = 0; i < n; ++i) {
            std::cin >> airports[i].x >> airports[i].y;
        }
        
        for (int i = 0; i < m; ++i) {
            std::cin >> flights[i].departure >> flights[i].arrival >> flights[i].speed;
        }
        
        double minCost = DBL_MAX;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double cost = calculateAverageCost(airports, flights, airports[i], airports[j]);
                minCost = std::min(minCost, cost);
            }
        }
        
        std::cout << minCost << std::endl;
    }
    
    return 0;
}