#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool consistentAssignment(vector<pair<int, int>>& assignments, int q) {
    vector<int> min_values(q+1, -1);
    
    for (auto& assignment : assignments) {
        int t = assignment.first;
        int a = assignment.second.first;
        int b = assignment.second.second;
        int y = assignment.second.second;
        
        if (t == 0) {
            for (int i = a; i <= b; i++) {
                if (min_values[i] == -1) min_values[i] = y;
                else if (min_values[i] != y) return false;
            }
        } else {
            for (int i = a; i <= b; i++) {
                min_values[i] = y;
            }
        }
    }
    
    return true;
}

int main() {
    int Q;
    cin >> Q;
    
    vector<pair<int, pair<int, int>> assignments;
    
    for (int i = 0; i < Q; i++) {
        int t, a, b, y;
        cin >> t >> a >> b >> y;
        assignments.push_back({t, {a, b, y}});
    }
    
    if (consistentAssignment(assignments, Q)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}