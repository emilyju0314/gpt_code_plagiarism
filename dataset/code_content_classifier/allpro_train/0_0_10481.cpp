#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> songs;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        songs.push_back({a, b});
    }

    sort(songs.begin(), songs.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second - a.first < b.second - b.first;
    });

    long long totalSize = 0;
    int numToCompress = 0;
    for(int i = 0; i < n; i++) {
        totalSize += songs[i].first;
        if(totalSize > m) {
            break;
        } else {
            numToCompress++;
        }
    }

    if(totalSize > m) {
        cout << "-1" << endl;
    } else {
        cout << numToCompress << endl;
    }

    return 0;
}