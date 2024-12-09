#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    for(int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    sort(segments.begin(), segments.end(), cmp);

    int mx = 0;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(segments[i].second <= mx) {
            cout << "NO" << endl;
            return 0;
        }
        mx = max(mx, segments[i].second);
    }

    cout << "YES" << endl;

    return 0;
}