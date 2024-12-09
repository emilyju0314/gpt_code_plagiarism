#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findImposters(int n, int m, vector<vector<pair<int, string>>> comments) {
    unordered_map<int, string> role;
    for(int i = 1; i <= n; i++) {
        role[i] = "unknown";
    }
    
    for(auto comment : comments) {
        int i = comment[0].first;
        int j = comment[1].first;
        string c = comment[1].second;
        
        if(role[i] == "unknown" && role[j] == "unknown") {
            role[i] = (c == "imposter") ? "crewmate" : "imposter";
            role[j] = c;
        } else if(role[i] == "unknown") {
            role[i] = (role[j] == c) ? "crewmate" : "imposter";
        } else if(role[j] == "unknown") {
            role[j] = (role[i] == c) ? c : (c == "imposter" ? "crewmate" : "imposter");
        } else {
            if((role[i] == "imposter" && c == "imposter") || (role[i] == "crewmate" && c == "crewmate") || (role[j] == c)) {
                continue;
            } else {
                return -1; // Contradiction
            }
        }
    }
    
    int imposters = count_if(role.begin(), role.end(), [&](const pair<int, string>& p) {
        return p.second == "imposter";
    });
    
    return imposters;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<pair<int, string>>> comments(m);
        for(int i = 0; i < m; i++) {
            int i, j;
            string c;
            cin >> i >> j >> c;
            comments[i].push_back({j, c});
        }
        
        int imposters = findImposters(n, m, comments);
        cout << imposters << endl;
    }
    
    return 0;
}