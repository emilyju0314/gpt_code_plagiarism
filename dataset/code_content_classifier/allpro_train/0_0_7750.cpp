#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Road {
    int A, B, C;
};

bool arePerpendicular(Road r1, Road r2) {
    return r1.A * r2.A + r1.B * r2.B == 0;
}

pair<int, vector<pair<int, int>>> solve(int n, int k, vector<Road>& roads) {
    if (k >= n - 1) {
        return make_pair(0, vector<pair<int, int>>());
    }

    vector<pair<int, int>> signs;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!arePerpendicular(roads[i], roads[j])) {
                signs.push_back(make_pair(i + 1, j + 1));
                if (signs.size() >= k) {
                    return make_pair(signs.size(), signs);
                }
            }
        }
    }

    return make_pair(0, vector<pair<int, int>>());
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Road> roads(n);
    for (int i = 0; i < n; ++i) {
        cin >> roads[i].A >> roads[i].B >> roads[i].C;
    }

    pair<int, vector<pair<int, int>>> solution = solve(n, k, roads);

    if (solution.first == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << solution.first << endl;
        for (auto sign : solution.second) {
            cout << sign.first << " " << sign.second << endl;
        }
    }

    return 0;
}