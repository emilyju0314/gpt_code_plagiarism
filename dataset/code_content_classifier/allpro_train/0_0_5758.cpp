#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int d, n, m;
    cin >> d >> n >> m;
    
    vector<pair<int, int>> stations;
    for(int i = 0; i < m; i++) {
        int x, p;
        cin >> x >> p;
        stations.push_back({x, p});
    }
    
    sort(stations.begin(), stations.end());
    
    int current_pos = 0;
    int current_tank = n;
    int cost = 0;
    
    for(int i = 0; i < m; i++) {
        int dist_to_next_station = stations[i].first - current_pos;
        if(current_tank < dist_to_next_station) {
            cost = -1;
            break;
        }
        
        current_tank -= dist_to_next_station;
        int refuel_amount = n - current_tank;
        int refuel_cost = refuel_amount * stations[i].second;
        cost += refuel_cost;
        current_tank = n;
        current_pos = stations[i].first;
    }
    
    if(cost != -1) {
        int dist_to_center = d - current_pos;
        if(current_tank < dist_to_center) {
            cost += (n - current_tank) * stations.back().second;
        }
    }
    
    if(cost != -1) {
        cout << cost << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}