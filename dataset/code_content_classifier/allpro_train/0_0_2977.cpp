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
    
    int team1_strength = 0, team2_strength = 0;
    
    for (int i = 0; i < m; i++) {
        char action;
        int team;
        cin >> action >> team;
        
        if (action == 'p') {
            if (team == 1) {
                int max_strength = *max_element(strengths.begin(), strengths.end());
                team1_strength += max_strength;
                strengths.erase(max_element(strengths.begin(), strengths.end()));
            } else {
                int max_strength = *max_element(strengths.begin(), strengths.end());
                team2_strength += max_strength;
                strengths.erase(max_element(strengths.begin(), strengths.end()));
            }
        } else {
            int weakest_strength = *min_element(strengths.begin(), strengths.end());
            strengths.erase(min_element(strengths.begin(), strengths.end()));
        }
    }
    
    cout << team1_strength - team2_strength << endl;
    
    return 0;
}