#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Road {
    int v, u, c, t, idx;
};

bool cmp(const Road &a, const Road &b) {
    return a.t < b.t;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Road> roads(m);
    for (int i = 0; i < m; i++) {
        cin >> roads[i].v >> roads[i].u >> roads[i].c >> roads[i].t;
        roads[i].idx = i + 1;
    }

    sort(roads.begin(), roads.end(), cmp);

    vector<Road> matching;
    vector<int> colors(n + 1, -1);

    int total_time = 0;
    for (int i = 0; i < m; i++) {
        int v = roads[i].v, u = roads[i].u, c = roads[i].c, t = roads[i].t;
        if (colors[v] == -1 && colors[u] == -1) {
            colors[v] = colors[u] = c;
            matching.push_back(roads[i]);
            total_time = max(total_time, t);
        } else if (colors[v] == -1 || colors[u] == -1 || colors[v] == c || colors[u] == c) {
            continue;
        } else {
            cout << "Yes" << endl;
            cout << total_time << " " << matching.size() << endl;
            for (Road road : matching) {
                cout << road.idx << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}