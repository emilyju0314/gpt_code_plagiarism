#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minTeams(vector<int>& skills) {
    int n = skills.size();
    sort(skills.begin(), skills.end());
    
    int teams = 1;
    for (int i = 1; i < n; i++) {
        if (skills[i] - skills[i-1] == 1) {
            teams = 2;
            break;
        }
    }
    
    return teams;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int n;
        cin >> n;
        
        vector<int> skills(n);
        for (int i = 0; i < n; i++) {
            cin >> skills[i];
        }
        
        cout << minTeams(skills) << endl;
    }
    
    return 0;
}