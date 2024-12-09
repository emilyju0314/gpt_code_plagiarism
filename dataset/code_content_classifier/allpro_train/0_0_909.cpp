#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> islands(n);
    for (int i = 0; i < n; i++) {
        cin >> islands[i].first >> islands[i].second;
    }

    vector<long long> bridges(m);
    for (int i = 0; i < m; i++) {
        cin >> bridges[i];
    }

    vector<long long> bridge_order(n-1, -1);

    sort(islands.begin(), islands.end());
    sort(bridges.begin(), bridges.end());

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            if (islands[i].second - islands[i].first == bridges[j]) {
                bridge_order[i] = bridges[j];
                break;
            }
        }

        if (bridge_order[i] == -1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n-1; i++) {
        cout << find(bridges.begin(), bridges.end(), bridge_order[i]) - bridges.begin() + 1 << " ";
    }

    return 0;
}