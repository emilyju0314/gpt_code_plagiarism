#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> bombs(n);
    for(int i = 0; i < n; i++) {
        cin >> bombs[i].first >> bombs[i].second;
    }
    
    // Find the number of steps to reach each bomb
    vector<int> steps(n);
    for(int i = 0; i < n; i++) {
        steps[i] = abs(bombs[i].first) + abs(bombs[i].second);
    }
    
    // Sort the bombs by the number of steps required to reach them
    sort(bombs.begin(), bombs.end(), [&steps](pair<int, int>& bomb1, pair<int, int>& bomb2) {
        return steps[distance(bombs.begin(), lower_bound(bombs.begin(), bombs.end(), bomb1))] < steps[distance(bombs.begin(), lower_bound(bombs.begin(), bombs.end(), bomb2))];
    });
    
    // Output the total number of operations needed
    cout << 4 * n << endl;
    
    // Output the sequence of operations
    for(int i = 0; i < n; i++) {
        // Move to the bomb
        if(bombs[i].first < 0) {
            cout << "1 " << abs(bombs[i].first) << " L" << endl;
        } else {
            cout << "1 " << abs(bombs[i].first) << " R" << endl;
        }
        
        if(bombs[i].second < 0) {
            cout << "1 " << abs(bombs[i].second) << " D" << endl;
        } else {
            cout << "1 " << abs(bombs[i].second) << " U" << endl;
        }
        
        // Pick and destroy the bomb
        cout << "2" << endl;
        
        // Move back to the origin
        if(bombs[i].first < 0) {
            cout << "1 " << abs(bombs[i].first) << " R" << endl;
        } else {
            cout << "1 " << abs(bombs[i].first) << " L" << endl;
        }
        
        if(bombs[i].second < 0) {
            cout << "1 " << abs(bombs[i].second) << " U" << endl;
        } else {
            cout << "1 " << abs(bombs[i].second) << " D" << endl;
        }
        
        // Destroy the bomb
        cout << "3" << endl;
    }
    
    return 0;
}