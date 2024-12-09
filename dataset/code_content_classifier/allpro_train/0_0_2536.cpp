#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<pair<pair<int, int>, pair<int, int>>> paths;
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        paths.push_back({{x1, y1}, {x2, y2}});
    }

    unordered_set<int> black_nodes;
    black_nodes.insert(0);

    for (auto path : paths) {
        int x1 = path.first.first, y1 = path.first.second;
        int x2 = path.second.first, y2 = path.second.second;
        while (true) {
            while (x1 != x2 || y1 != y2) {
                if (x1 > x2) {
                    x1 >>= 1;
                } else {
                    y1 >>= 1;
                }
                int node = x1 + y1 * 1000000000;
                black_nodes.insert(node);
            }
            if (x1 == 0 && y1 == 0) break;
            x1 >>= 1;
            y1 >>= 1;
            int node = x1 + y1 * 1000000000;
            black_nodes.insert(node);
        }
    }

    // Calculate the minimum number of cheating operations needed
    int min_cheating_operations = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int parent = (node >> 1);
        if (black_nodes.find(parent) == black_nodes.end()) {
            black_nodes.insert(parent);
            min_cheating_operations++;
            q.push(parent);
        }
    }

    cout << min_cheating_operations << endl;

    return 0;
}