#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    
    vector<pair<int, int>> stations; // pair of (coordinate, index)
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stations.push_back({x, i+1});
    }
    
    cin >> k;
    
    sort(stations.begin(), stations.end());
    
    long long min_avg_time = LLONG_MAX;
    vector<int> chosen_stations;
    
    for (int i = 0; i <= n - k; i++) {
        long long avg_time = 0;
        
        for (int j = i; j < i + k - 1; j++) {
            avg_time += abs(stations[j].first - stations[j+1].first);
        }
        
        if (avg_time < min_avg_time) {
            min_avg_time = avg_time;
            chosen_stations.clear();
            for (int j = i; j < i + k; j++) {
                chosen_stations.push_back(stations[j].second);
            }
        }
    }
    
    for (int station : chosen_stations) {
        cout << station << " ";
    }
    
    return 0;
}