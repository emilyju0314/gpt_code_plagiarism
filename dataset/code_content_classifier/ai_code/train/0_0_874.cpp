#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> songs(n);
    for (int i = 0; i < n; i++) {
        int t, b;
        cin >> t >> b;
        songs[i] = {b, t};
    }

    sort(songs.rbegin(), songs.rend());

    long long total_length = 0;
    long long min_beauty = 1e6;
    long long max_pleasure = 0;

    for (int i = 0; i < k; i++) {
        total_length += songs[i].second;
        min_beauty = min(min_beauty, (long long)songs[i].first);
        max_pleasure = max(max_pleasure, total_length * min_beauty);
    }

    cout << max_pleasure << endl;

    return 0;
}