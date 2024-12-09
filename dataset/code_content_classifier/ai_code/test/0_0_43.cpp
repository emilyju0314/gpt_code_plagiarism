#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Road {
    int capacity;
    int toll;
};

struct City {
    int enjoyment;
    vector<Road> roads;
};

vector<City> cities;

pair<int, int> findMaxEnjoyment(int groupSize, int startCity) {
    vector<int> maxEnjoyment(cities.size(), 0);
    vector<int> minToll(cities.size(), INT_MAX);

    queue<int> q;
    q.push(startCity);
    while (!q.empty()) {
        int currCity = q.front();
        q.pop();

        for (Road road : cities[currCity].roads) {
            int nextCity = (currCity == startCity) ? (road.capacity >= groupSize ? currCity : -1) : road.capacity >= groupSize ? currCity : -1;

            if (nextCity != -1) {
                if (cities[nextCity].enjoyment > maxEnjoyment[nextCity]) {
                    maxEnjoyment[nextCity] = cities[nextCity].enjoyment;
                    minToll[nextCity] = road.toll;
                } else if (cities[nextCity].enjoyment == maxEnjoyment[nextCity]) {
                    minToll[nextCity] = min(minToll[nextCity], road.toll);
                }
                q.push(nextCity);
            }
        }
    }

    int maxEnjoymentValue = 0;
    int minTollValue = 0;
    for (int i = 0; i < cities.size(); i++) {
        if (maxEnjoyment[i] > maxEnjoymentValue) {
            maxEnjoymentValue = maxEnjoyment[i];
            minTollValue = minToll[i];
        } else if (maxEnjoyment[i] == maxEnjoymentValue) {
            minTollValue = min(minTollValue, minToll[i]);
        }
    }

    return {maxEnjoymentValue, minTollValue};
}

int main() {
    int n, q;
    cin >> n >> q;

    cities.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> cities[i].enjoyment;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        a--;
        b--;

        cities[a].roads.push_back({c, t});
        cities[b].roads.push_back({c, t});
    }

    for (int i = 0; i < q; i++) {
        int v, x;
        cin >> v >> x;
        x--;

        pair<int, int> result = findMaxEnjoyment(v, x);
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}