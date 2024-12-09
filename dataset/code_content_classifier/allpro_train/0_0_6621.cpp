#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int C;
    cin >> C;

    vector<pair<int, int>> hotels;

    for (int i = 0; i < C; i++) {
        int x, y;
        cin >> x >> y;
        hotels.push_back({x, y});
    }

    int H;
    cin >> H;

    vector<pair<int, int>> restaurants;

    for (int i = 0; i < H; i++) {
        int x, y;
        cin >> x >> y;
        restaurants.push_back({x, y});
    }

    int minDistance = INT_MAX;
    int optimalRestaurantIndex = -1;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < C; j++) {
            int distance = abs(hotels[j].first - restaurants[i].first) + abs(hotels[j].second - restaurants[i].second);
            if (distance < minDistance) {
                minDistance = distance;
                optimalRestaurantIndex = i + 1;
            }
        }
    }

    cout << minDistance << endl;
    cout << optimalRestaurantIndex << endl;

    return 0;
}