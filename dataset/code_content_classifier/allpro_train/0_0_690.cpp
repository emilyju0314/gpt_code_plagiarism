#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments;
    map<int, int> points;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segments.push_back({l, r});

        points[l]++;
        points[r+1]--;
    }

    int covered = 0;
    map<int, int> count;

    for (auto& p : points) {
        covered += p.second;
        count[covered]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << count[i] << " ";
    }

    return 0;
}