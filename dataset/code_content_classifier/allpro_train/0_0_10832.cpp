#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }

    unordered_map<int, vector<int>> idx;
    for (int i = 0; i < 2 * n; i++) {
        idx[a[i]].push_back(i);
    }

    long long int total_dist = 0;
    int sasha_pos = 0;
    int dima_pos = 0;

    for (int i = 1; i <= n; i++) {
        int sasha_dist = abs(idx[i][0] - sasha_pos) + abs(idx[i][1] - dima_pos);
        int dima_dist = abs(idx[i][1] - dima_pos) + abs(idx[i][0] - sasha_pos);
        total_dist += min(sasha_dist, dima_dist);
        sasha_pos = idx[i][0];
        dima_pos = idx[i][1];
    }

    cout << total_dist << endl;

    return 0;
}