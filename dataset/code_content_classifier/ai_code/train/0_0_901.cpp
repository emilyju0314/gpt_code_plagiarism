#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> heads(n);
    vector<int> tracks(m);

    for(int i = 0; i < n; i++) {
        cin >> heads[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> tracks[i];
    }

    int minTime = 0;

    for(int i = 0; i < m; i++) {
        int closestHead = 0;
        int minDiff = INT_MAX;

        for(int j = 0; j < n; j++) {
            int diff = abs(tracks[i] - heads[j]);
            if(diff < minDiff) {
                closestHead = j;
                minDiff = diff;
            }
        }

        minTime = max(minTime, minDiff);
    }

    cout << minTime << endl;

    return 0;
}