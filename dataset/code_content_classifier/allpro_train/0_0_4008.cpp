#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> players(n);
        for(int i = 0; i < n; i++) {
            cin >> players[i].first;
            players[i].second = i + 1;
        }

        sort(players.begin(), players.end());

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(players[i].first < players[n-1].first) {
                cnt++;
            } else {
                break;
            }
        }

        cout << cnt << endl;
        for(int i = n - cnt; i < n; i++) {
            cout << players[i].second << " ";
        }
        cout << endl;
    }

    return 0;
}