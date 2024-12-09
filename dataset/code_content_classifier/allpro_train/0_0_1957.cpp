#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isReasonableNetwork(int n, const vector<pair<int, int>>& friendships) {
    unordered_set<int> friends[n+1];
    
    for (const auto& p : friendships) {
        friends[p.first].insert(p.second);
        friends[p.second].insert(p.first);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j : friends[i]) {
            for (int k : friends[j]) {
                if (friends[i].count(k) == 0) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> friendships;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friendships.push_back({a, b});
    }
    
    if (isReasonableNetwork(n, friendships)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}