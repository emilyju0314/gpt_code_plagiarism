#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> people;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        people.push_back({x, y});
    }

    double max_distance = 1e9; // initialize max_distance to a very large number
    for (int i = 0; i < n; i++) {
        int x1 = people[i].first;
        int y1 = people[i].second;
        for (int j = i+1; j < n; j++) {
            int x2 = people[j].first;
            int y2 = people[j].second;
            max_distance = min(max_distance, distance(x1, y1, x2, y2)/2.0); // divide by 2 to get the distance to the barrier
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        max_distance = min(max_distance, distance(0, 0, x, y));
    }

    cout << fixed;
    cout.precision(10);
    cout << max_distance << endl;

    return 0;
}