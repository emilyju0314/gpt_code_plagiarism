#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> mice(n);
    for (int i = 0; i < n; i++) {
        cin >> mice[i];
    }

    vector<pair<int, int>> holes(m);
    for (int i = 0; i < m; i++) {
        cin >> holes[i].first >> holes[i].second;
    }

    sort(mice.begin(), mice.end());
    sort(holes.begin(), holes.end());

    long long sum = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
        while (current < m && holes[current].second == 0) {
            current++;
        }
        if (current == m) {
            cout << -1 << endl;
            return 0;
        }
        if (mice[i] < holes[current].first) {
            sum += abs(mice[i] - holes[current].first);
        } else if (mice[i] > holes[current].first) {
            sum += abs(mice[i] - holes[current].first);
            holes[current].second--;
        } else {
            sum += abs(mice[i] - holes[current].first);
            holes[current].second--;
            current++;
        }
        
    }

    cout << sum << endl;

    return 0;
}