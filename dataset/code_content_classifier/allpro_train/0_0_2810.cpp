#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<pair<int, int>> ducks(n);
    for (int i = 0; i < n; i++) {
        int h, t;
        cin >> h >> t;
        ducks[i] = {h, t};
    }

    sort(ducks.begin(), ducks.end());

    int cnt = 0;
    int shooting_time = 0;
    for (int i = 0; i < n; i++) {
        if (ducks[i].first > shooting_time) {
            cnt++;
            shooting_time = ducks[i].first + r;
        }
        else if (ducks[i].second >= shooting_time) {
            cnt++;
            shooting_time = ducks[i].second + r;
        }
    }

    cout << cnt << endl;

    return 0;
}