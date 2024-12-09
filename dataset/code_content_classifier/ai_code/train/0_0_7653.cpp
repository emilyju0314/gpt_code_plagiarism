#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> queries(t);
    unordered_map<pair<int, int>, int> ants;

    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        queries[i] = {x, y};
    }

    int time = 0;
    while (n >= 4) {
        unordered_map<pair<int, int>, int> new_ants;
        for (const auto& ant : ants) {
            int x = ant.first.first;
            int y = ant.first.second;
            int count = ant.second;
            int spread = count / 4;
            n += count % 4;
            new_ants[{x+1, y}] += spread;
            new_ants[{x-1, y}] += spread;
            new_ants[{x, y+1}] += spread;
            new_ants[{x, y-1}] += spread;
        }
        ants = new_ants;
        time++;
    }

    for (const auto& query : queries) {
        int x = query.first;
        int y = query.second;
        if (time == 0 || abs(x) + abs(y) > time) {
            cout << "0" << endl;
        } else {
            int remaining = n;
            if (abs(x) + abs(y) == time) {
                remaining += ants[{x, y}];
            }
            cout << remaining << endl;
        }
    }

    return 0;
}