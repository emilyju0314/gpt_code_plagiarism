#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> max_score(n, 0);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        max_score[v-1] = max(max_score[v-1], a[u-1]);
    }
    
    for(int i = 0; i < n; i++) {
        max_score[i] = max(max_score[i], a[i]);
    }
    
    for(int i = 0; i < n; i++) {
        cout << max_score[i] << " ";
    }
    
    return 0;
}