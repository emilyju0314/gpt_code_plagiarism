#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
    int city1;
    int city2;
    int speed;

    Road(int c1, int c2, int s) {
        city1 = c1;
        city2 = c2;
        speed = s;
    }

    bool operator<(const Road& other) const {
        return speed < other.speed;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<Road> roads;
        for (int i = 0; i < m; i++) {
            int x, y, s;
            cin >> x >> y >> s;
            roads.push_back(Road(x, y, s));
        }

        sort(roads.begin(), roads.end());

        vector<int> parent(n+1);
        iota(parent.begin(), parent.end(), 0);

        int remaining_roads = 0;
        int changes = 0;
        int max_speed = 0;

        for (Road road : roads) {
            int city1 = road.city1;
            int city2 = road.city2;
            int speed = road.speed;

            while (parent[city1] != city1) {
                city1 = parent[city1];
            }

            while (parent[city2] != city2) {
                city2 = parent[city2];
            }

            if (city1 != city2) {
                parent[city2] = city1;
                remaining_roads++;
                max_speed = max(max_speed, speed);
            }

            if (remaining_roads == n - 1) {
                break;
            }
        }

        changes = abs(max_speed - k);
        cout << changes << endl;
    }

    return 0;
}