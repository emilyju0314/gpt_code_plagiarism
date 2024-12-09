#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> shows;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        shows.push_back(make_pair(l, r));
    }

    sort(shows.begin(), shows.end());

    int end1 = -1, end2 = -1;

    for (int i = 0; i < n; i++) {
        if (shows[i].first > end1) {
            end1 = shows[i].second;
        } else if (shows[i].first > end2) {
            end2 = shows[i].second;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}