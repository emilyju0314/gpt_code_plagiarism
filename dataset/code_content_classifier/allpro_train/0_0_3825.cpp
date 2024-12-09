#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> goals(n);
    for (int i = 0; i < n; i++) {
        cin >> goals[i];
    }
    
    int q;
    cin >> q;
    
    vector<vector<pair<int, int>>> milestones(n); // store milestones for each resource
    
    vector<int> num_resources(n, 0); // current number of resources for each type
    
    long long total_turns = 0; // total number of turns needed
    
    for (int i = 0; i < q; i++) {
        int s, t, u;
        cin >> s >> t >> u;
        s--;
        t--;
        u--;
        
        int prev_milestone = -1;
        for (int j = 0; j < milestones[s].size(); j++) {
            if (milestones[s][j].first == t) {
                prev_milestone = j;
                break;
            }
        }
        
        if (prev_milestone != -1) {
            if (u != -1) {
                milestones[s][prev_milestone].second = u;
            } else {
                milestones[s].erase(milestones[s].begin() + prev_milestone);
            }
        } else {
            if (u != -1) {
                milestones[s].push_back({t, u});
            }
        }
        
        int min_turns = 1e9;
        for (int j = 0; j < milestones[s].size(); j++) {
            min_turns = min(min_turns, goals[s] - num_resources[s] + milestones[s][j].second);
        }
        
        total_turns += min_turns;
        
        num_resources[s] = min(num_resources[s] + min_turns, goals[s]);
        
        cout << total_turns << endl;
    }
    
    return 0;
}