#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> blocked(m);
    for(int i = 0; i < m; i++) {
        cin >> blocked[i];
    }
    
    sort(blocked.begin(), blocked.end());

    vector<int> costs(k);
    for(int i = 0; i < k; i++) {
        cin >> costs[i];
    }

    int total_cost = INT_MAX;

    for(int i = 1; i <= k; i++) {
        bool possible = true;
        int cost = 0;
        int last = 0;
        for(int j = 0; j < m; j++) {
            if(blocked[j] - last <= i) {
                possible = false;
                break;
            } else {
                cost += costs[i-1];
                last = blocked[j];
            }
        }

        if(n - last <= i) {
            possible = false;
        } else {
            cost += costs[i-1];
        }

        if(possible) {
            total_cost = min(total_cost, cost);
        }
    }

    if(total_cost == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << total_cost << endl;
    }

    return 0;
}