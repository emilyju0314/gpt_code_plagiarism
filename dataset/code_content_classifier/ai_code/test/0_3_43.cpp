#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Road {
    int city1;
    int city2;
    int capacity;
    int toll;
};

struct City {
    int enjoyment_value;
    vector<Road> roads;
};

struct TourGroup {
    int num_vehicles;
    int starting_city;
};

int maxEnjoyment(int n, vector<City>& cities, TourGroup group) {
    // Implement this function to calculate the maximum enjoyment value a tour group can reach from a starting city
}

void shortestPath(int n, vector<City>& cities, int start_city) {
    // Implement this function to find the shortest path from the starting city to each city
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<City> cities(n);

    for (int i = 0; i < n; ++i) {
        cin >> cities[i].enjoyment_value;
    }

    for (int i = 0; i < n-1; ++i) {
        Road road;
        cin >> road.city1 >> road.city2 >> road.capacity >> road.toll;
        cities[road.city1-1].roads.push_back(road);
        cities[road.city2-1].roads.push_back(road);
    }

    vector<TourGroup> groups(q);

    for (int i = 0; i < q; ++i) {
        cin >> groups[i].num_vehicles >> groups[i].starting_city;
    }

    for (int i = 0; i < q; ++i) {
        int max_enjoyment = maxEnjoyment(n, cities, groups[i]);
        cout << max_enjoyment << " " << "TODO" << endl;
    }

    return 0;
}