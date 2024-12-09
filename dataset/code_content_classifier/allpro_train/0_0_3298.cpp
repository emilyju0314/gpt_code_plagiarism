#include <iostream>
#include <vector>
#include <map>

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<int> hostCities(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> hostCities[i];
    }

    std::map<int, int> cityFrequency;
    for (int city : hostCities) {
        cityFrequency[city]++;
    }

    int minFrequency = cityFrequency.begin()->second;
    std::vector<int> result;
    for (int city : hostCities) {
        if (cityFrequency[city] == minFrequency) {
            result.push_back(city);
        }
    }

    for (int i = 0; i < q; ++i) {
        long long year;
        std::cin >> year;
        year -= n;
        year--;
        result.push_back(result[year % result.size()]);
    }

    for (int city : result) {
        std::cout << city << std::endl;
    }

    return 0;
}