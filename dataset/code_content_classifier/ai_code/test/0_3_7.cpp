#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string a, b;
    cin >> a >> b;
    
    vector<int> result(n - m + 2, -1); // Initialize result vector with -1
    
    for(int k = 0; k <= n - m + 1; k++) {
        int changes = 0;
        for(int i = 0; i < m; i++) {
            if(a[i] != b[i]) {
                changes++;
            }
        }
        
        result[k] = changes;
        
        for(int i = m; i < n; i++) {
            if(a[i] != b[i - m]) {
                changes--;
            }
            if(a[i - m] != b[0]) {
                changes++;
            }
            
            result[k] = min(result[k], changes);
        }
        
        a += '0'; // Extend a by one character for next iteration
    }
    
    for(int i = 0; i < n - m + 2; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}