#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int x = a[n-1];
        int k = 0, count = 0;
        
        for(int i = n-2; i >= 0; i--) {
            if(a[i] > x) {
                x = a[i];
                count++;
            }
            k = max(k, count);
        }
        
        cout << k << endl;
    }
    
    return 0;
}