#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);

    for(int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    // Sort the segments based on their starting points
    sort(segments.begin(), segments.end());

    for(int i = 1; i < n; i++) {
        if(segments[i].second >= segments[i-1].second) {
            cout << i << " " << i+1 << endl;
            return 0;
        }
    }

    cout << "-1 -1" << endl;

    return 0;
}