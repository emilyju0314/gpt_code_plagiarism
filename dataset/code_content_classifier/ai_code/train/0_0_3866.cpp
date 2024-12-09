#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<int> parent(m + 1);
    vector<int> level(m + 1, 0);

    for (int i = 2; i <= m + 1; i++) {
        cin >> parent[i];
        level[i] = level[parent[i]] + 1;
    }

    vector<int> max_distance(m + 1, 0);
    vector<int> count(m + 1, 0);

    for (int i = m + 1; i >= 2; i--) {
        max_distance[i] = max(max_distance[i], level[i]);
        count[max_distance[i]]++;
        max_distance[parent[i]] = max(max_distance[parent[i]], max_distance[i]);
        count[max_distance[parent[i]]] += count[max_distance[i]];
    }

    for (int i = 2; i <= m + 1; i++) {
        cout << count[i] << endl;
    }

    return 0;
}