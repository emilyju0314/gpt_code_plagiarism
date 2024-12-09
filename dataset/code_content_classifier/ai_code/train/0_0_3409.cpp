#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> teeth;
    for(int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        teeth.push_back(make_pair(r, c));
    }

    sort(teeth.begin(), teeth.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    int total_crucians = 0;
    for(int i = 0; i < n; i++) {
        if(k >= teeth[i].second) {
            total_crucians += teeth[i].second;
            k -= teeth[i].second;
        } else {
            total_crucians += k;
            break;
        }
    }

    cout << total_crucians << endl;

    return 0;
}