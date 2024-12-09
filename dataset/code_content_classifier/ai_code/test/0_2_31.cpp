#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        vector<int> b(n);
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        
        int acc = 0;
        for(int i = 0; i < n - 1; i++) {
            b[i] = 1;
            acc += a[i] * b[i];
        }
        
        b[n - 1] = -acc + sum;
        
        for(int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}