#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> pots(n);
    for(int i=0; i<n; i++) {
        cin >> pots[i];
    }
    
    unordered_map<int, int> untasted;
    for(int i=0; i<n; i++) {
        untasted[i] = pots[i];
    }
    
    cin >> q;
    double m = 0.0;
    int totalUntasted = n;
    
    for(int i=0; i<q; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        
        m += (double)totalUntasted / n;
        
        for(int j=0; j<k; j++) {
            int numTasted = min(untasted[u-1], 1);
            untasted[u-1] -= numTasted;
            if(untasted[u-1] == 0) totalUntasted--;
            
            untasted[v-1] += numTasted;
        }
    }
    
    cout.precision(12);
    for(int i=0; i<q; i++) {
        cout << m << endl;
    }
    
    return 0;
}