#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<vector<int>> roads;
vector<int> junctions;
int result = 0;

bool isValidClosure(vector<int>& closure) {
    vector<int> degree(n, 0);
    int deadEnds = 0;

    for (int i = 0; i < m; i++) {
        if (closure[i] == 0) {
            degree[roads[i][0] - 1]++;
            degree[roads[i][1] - 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
            deadEnds++;
        }
    }

    return deadEnds == k;
}

void countClosures(vector<int>& closure, int idx, int roadsLeft) {
    if (idx == m) {
        if (roadsLeft == n - 1 && isValidClosure(closure)) {
            result++;
        }
        return;
    }

    closure[idx] = 1;
    countClosures(closure, idx + 1, roadsLeft - 1);

    closure[idx] = 0;
    countClosures(closure, idx + 1, roadsLeft);
}

int main() {
    cin >> n >> m >> k;

    roads.resize(m);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        roads[i] = {v1, v2};
    }

    vector<int> closure(m, 0);
    countClosures(closure, 0, n - 1);

    cout << result << endl;

    return 0;
}