#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string t;
    cin >> t;
    
    int n;
    cin >> n;
    
    vector<pair<string, int>> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i].first >> strings[i].second;
    }

    int total_cost = 0;
    for(char c : t) {
        vector<int> costs;
        for(int i = 0; i < n; i++) {
            size_t idx = strings[i].first.find(c);
            if(idx != string::npos && idx <= strings[i].second) {
                costs.push_back(i+1);
            }
        }
        if(costs.empty()) {
            cout << -1 << endl;
            return 0;
        }
        sort(costs.begin(), costs.end());
        total_cost += costs[0];
        strings[costs[0]-1].first.erase(remove(strings[costs[0]-1].first.begin(), strings[costs[0]-1].first.end(), c),
                                         strings[costs[0]-1].first.end());
    }
    
    cout << total_cost << endl;
    
    return 0;
}