#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Flight {
    int day;
    int departure_city;
    int arrival_city;
    int cost;
};

bool compareFlights(const Flight& f1, const Flight& f2) {
    return f1.day < f2.day;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Flight> flights;

    for (int i = 0; i < m; i++) {
        Flight f;
        cin >> f.day >> f.departure_city >> f.arrival_city >> f.cost;
        flights.push_back(f);
    }

    sort(flights.begin(), flights.end(), compareFlights);

    vector<int> min_cost(n+1, INT_MAX);

    for (int i = 0; i < m; i++) {
        int departure_city = flights[i].departure_city;
        int arrival_city = flights[i].arrival_city;
        int cost = flights[i].cost;

        if (departure_city == 0) {
            min_cost[arrival_city] = min(min_cost[arrival_city], cost);
        } else {
            if (min_cost[departure_city] != INT_MAX) {
                min_cost[arrival_city] = min(min_cost[arrival_city], min_cost[departure_city] + cost);
            }
        }
    }

    int total_cost = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (min_cost[i] != INT_MAX) {
            total_cost = min(total_cost, min_cost[i]);
        }
    }

    if (total_cost == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << total_cost * 2 << endl; // Round trip cost
    }

    return 0;
}