#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<pair<int, int>, pair<int, int>>> intervals(N);
    for (int i = 0; i < N; i++) {
        cin >> intervals[i].first.first >> intervals[i].first.second 
            >> intervals[i].second.first >> intervals[i].second.second;
    }

    for (int q = 0; q < Q; q++) {
        int x, y, z, w;
        cin >> x >> y >> z >> w;

        bool found = false;
        for (int i = 0; i < N; i++) {
            if (x < intervals[i].first.first && intervals[i].first.first < y
                && z < intervals[i].second.first && intervals[i].second.first < w) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}