#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for(int i=0; i<n; i++) {
        cin >> p[i];
    }

    unordered_map<int, int> changeMap;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        changeMap[u] = v;
    }

    int ans = 0;
    for(int i=n-1; i>0; i--) {
        if(changeMap.find(p[i]) != changeMap.end() && changeMap[p[i]] == p[i-1]) {
            swap(p[i], p[i-1]);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}