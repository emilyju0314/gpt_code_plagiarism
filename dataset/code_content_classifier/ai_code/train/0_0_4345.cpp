#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    
    vector<pair<int, int>> games(m);
    for (int i = 0; i < m; i++) {
        cin >> games[i].first >> games[i].second;
    }
    
    vector<int> stadium_count(k, 0);
    
    vector<int> stadium_assignments(m, 0);
    
    for (int i = 0; i < m; i++) {
        int t = 1;
        while (true) {
            if (stadium_count[t-1] <= stadium_count[t] && stadium_count[t-1] <= stadium_count[t+1]) {
                stadium_assignments[i] = t;
                stadium_count[t-1]++;
                break;
            }
            t++;
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << stadium_assignments[i] << endl;
    }
    
    return 0;
}