#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long x0, y0, ax, ay, bx, by, xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;

    vector<pair<long long, long long>> nodes;
    nodes.push_back(make_pair(x0, y0));

    // Generate all the data nodes based on the given formula
    while (true) {
        long long next_x = ax * nodes.back().first + bx;
        long long next_y = ay * nodes.back().second + by;
        if (next_x < 0 || next_y < 0 || next_x > 1e16 || next_y > 1e16) {
            break;
        }
        nodes.push_back(make_pair(next_x, next_y));
    }

    int n = nodes.size();
    int max_nodes = 0;

    for (int i = 0; i < n; i++) {
        long long remaining_time = t - abs(xs - nodes[i].first) - abs(ys - nodes[i].second);
        if (remaining_time < 0) {
            continue;
        }
        
        int collected_nodes = 1;
        for (int j = i + 1; j < n; j++) {
            long long travel_time = abs(nodes[j].first - nodes[i].first) + abs(nodes[j].second - nodes[i].second);
            if (travel_time <= remaining_time) {
                remaining_time -= travel_time;
                collected_nodes++;
            } else {
                break;
            }
        }
        max_nodes = max(max_nodes, collected_nodes);
    }

    cout << max_nodes << endl;

    return 0;
}