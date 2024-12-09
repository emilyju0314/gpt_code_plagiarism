#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> edges(n+1, 0);
    
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u]++;
        edges[v]++;
    }
    
    int sum = 0;
    for(int i=1; i<=n; i++) {
        sum += edges[i];
    }
    
    cout << sum+1 << endl;
    
    return 0;
}