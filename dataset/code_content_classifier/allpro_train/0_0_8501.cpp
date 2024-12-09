#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    multiset<pair<int, int>> sorted;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted.insert({a[i], i});
    }
    
    int m;
    cin >> m;
    
    while (m--) {
        int k, pos;
        cin >> k >> pos;
        
        vector<pair<int, int>> removed;
        vector<int> res;
        
        while (k--) {
            auto it = --sorted.end();
            res.push_back(it->first);
            removed.push_back(*it);
            sorted.erase(it);
        }
        
        for (auto p : removed) {
            sorted.insert(p);
        }
        
        sort(res.begin(), res.end());
        cout << res[res.size() - pos] << endl;
    }
    
    return 0;
}