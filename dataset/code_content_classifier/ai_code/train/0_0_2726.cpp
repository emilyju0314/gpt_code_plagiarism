#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<pair<int, int>> edges;
    for(int i = 1; i < n; i++) {
        if(p[i-1] < p[i]) {
            edges.push_back({p[i-1], p[i]});
        } else {
            edges.push_back({p[i], p[i-1]});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    for(int i = 1; i < n; i++) {
        if(edges[i-1] != make_pair(i, p[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    for(auto edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }
    
    return 0;
}