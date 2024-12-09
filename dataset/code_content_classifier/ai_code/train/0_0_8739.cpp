#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int dist, n, m;
    cin >> dist >> n;
    
    vector<int> speeds(n);
    for (int i = 0; i < n; i++) {
        cin >> speeds[i];
    }
    
    cin >> m;
    vector<int> distances(m);
    for (int i = 0; i < m; i++) {
        cin >> distances[i];
    }
    
    // Sort the distances to calculate the time taken by each carriage to reach the goal point
    sort(distances.begin(), distances.end());
    
    int first_carriage_time = dist / speeds[0];
    int total_time = first_carriage_time;
    
    for (int i = 1; i < n; i++) {
        int time = dist / speeds[i];
        
        // Calculate the additional time needed for the carriage to overtake previous carriages
        if (i <= m) {
            time += min(distances[i-1], dist - distances[i-1]) * 2;
        }
        
        total_time = max(total_time, time);
    }
    
    cout << total_time << endl;
    
    return 0;
}