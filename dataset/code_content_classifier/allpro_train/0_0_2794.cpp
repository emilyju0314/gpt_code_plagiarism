#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    vector<int> to_delete(k);
    for (int i = 0; i < k; i++) {
        to_delete[i] = i+1;
    }

    for (int i = k; i < n; i++) {
        if (points[to_delete[0]-1] < points[i]) {
            to_delete[0] = i+1;
            sort(to_delete.begin(), to_delete.end());
        }
    }

    for (int i = 0; i < k; i++) {
        cout << to_delete[i] << " ";
    }

    return 0;
}