#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> bids(n);
    for (int i = 0; i < n; i++) {
        cin >> bids[i].first >> bids[i].second;
    }
    
    int q;
    cin >> q;
    
    unordered_map<int, vector<pair<int, int>>> remainingBids;
    for (int i = 0; i < n; i++) {
        remainingBids[bids[i].first].push_back(bids[i]);
    }
    
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        
        vector<int> absentParticipants(k);
        for (int j = 0; j < k; j++) {
            cin >> absentParticipants[j];
        }
        
        vector<pair<int, int>> remaining;
        for (int j = 1; j <= n; j++) {
            if (find(absentParticipants.begin(), absentParticipants.end(), j) == absentParticipants.end()) {
                remaining.insert(remaining.end(), remainingBids[j].begin(), remainingBids[j].end());
            }
        }
        
        if (remaining.size() == 0) {
            cout << "0 0" << endl;
        } else {
            sort(remaining.begin(), remaining.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            });
            cout << remaining[0].first << " " << remaining[0].second << endl;
        }
    }
    
    return 0;
}