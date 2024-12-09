#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n, q, a[MAXN], p[MAXN];

vector<int> path;
map<int, int> freq;

void dfs(int v) {
    path.push_back(a[v]);
    freq[a[v]]++;
    
    for(int i = 2; i <= n; i++) {
        if(p[i] == v) {
            dfs(i);
        }
    }
    
    freq[a[v]]--;
    if(freq[a[v]] == 0) path.pop_back();
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 2; i <= n; i++) {
            cin >> p[i];
        }
        
        for(int i = 0; i < q; i++) {
            int v, l, k;
            cin >> v >> l >> k;
            
            path.clear();
            freq.clear();
            
            dfs(v);
            
            vector<int> uniquePath(path.begin(), path.end());
            sort(uniquePath.begin(),uniquePath.end());
            uniquePath.erase(unique(uniquePath.begin(), uniquePath.end()), uniquePath.end());
            
            vector<pair<int, int>> count;
            for(int num : uniquePath) {
                count.push_back({num, freq[num]});
            }
            sort(count.begin(), count.end(), [&](pair<int, int>& a, pair<int, int>& b){
                if(a.second != b.second) return a.second < b.second;
                return false;
            });
            
            int ans = -1;
            for(auto &pair : count) {
                if(pair.second >= l) {
                    k--;
                    if(k == 0) {
                        ans = pair.first;
                        break;
                    }
                }
            }
            
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}