#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    vector<int> strengths(n);
    for (int i = 0; i < n; i++) {
        cin >> strengths[i];
    }
    
    cin >> m;
    
    vector<int> picks(2), bans(2);
    
    for (int i = 0; i < m; i++) {
        char action;
        int team;
        cin >> action >> team;
        
        if (action == 'p') {
            picks[team - 1]++;
        } else if (action == 'b') {
            bans[team - 1]++;
        }
    }
    
    sort(strengths.begin(), strengths.end(), greater<int>());
    
    int totalStrengths[2] = {0, 0};
    
    for (int i = 0; i < n; i++) {
        if (picks[0] + bans[1] >= i) {
            totalStrengths[0] += strengths[i];
        } else {
            totalStrengths[1] += strengths[i];
        }
        
        if (picks[1] + bans[0] >= i) {
            totalStrengths[1] += strengths[i];
        } else {
            totalStrengths[0] += strengths[i];
        }
    }
    
    cout << totalStrengths[0] - totalStrengths[1] << endl;
    
    return 0;
}