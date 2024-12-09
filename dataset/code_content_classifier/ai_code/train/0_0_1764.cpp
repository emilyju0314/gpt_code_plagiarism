#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<int, int> cityMap;
    std::vector<std::pair<int, int>> stamps;
    
    for (int i = 0; i < n; ++i) {
        int city1, city2;
        std::cin >> city1 >> city2;
        stamps.push_back(std::make_pair(city1, city2));
        cityMap[city1]++;
        cityMap[city2]++;
    }

    int startCity;
    for (const auto& entry : cityMap) {
        if (entry.second == 1) {
            startCity = entry.first;
            break;
        }
    }

    std::vector<int> route;
    route.push_back(startCity);
    std::pair<int, int> currentStamp = stamps[0];
    while (route.size() < n + 1) {
        if (currentStamp.first == startCity) {
            route.push_back(currentStamp.second);
            startCity = currentStamp.second;
        } else {
            route.push_back(currentStamp.first);
            startCity = currentStamp.first;
        }
        for (const auto& stamp : stamps) {
            if (stamp.first == startCity || stamp.second == startCity) {
                currentStamp = stamp;
                break;
            }
        }
    }

    for (int city : route) {
        std::cout << city << " ";
    }

    return 0;
}