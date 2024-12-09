#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Road {
    int v, u, c, t, idx;
};

bool compareRoads(const Road& r1, const Road& r2) {
    return r1.t < r2.t;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Road> roads(m);
    for(int i = 0; i < m; i++) {
        cin >> roads[i].v >> roads[i].u >> roads[i].c >> roads[i].t;
        roads[i].idx = i+1;
    }

    sort(roads.begin(), roads.end(), compareRoads);

    vector<int> matching;
    set<int> colors;
    for(int i = 0; i < m; i++) {
        if(colors.find(roads[i].c) == colors.end()) {
            matching.push_back(roads[i].idx);
            colors.insert(roads[i].c);
        }
    }

    if(colors.size() < n/2) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        int total_time = 0;
        for(int i = 0; i < n/2; i++) {
            total_time = max(total_time, roads[i].t);
        }
        cout << total_time << " " << n/2 << endl;
        for(int i = 0; i < n/2; i++) {
            cout << matching[i] << " ";
        }
        cout << endl;
    }

    return 0;
}