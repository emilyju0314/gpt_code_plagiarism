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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool possible = true;
        for(int i = 0; i < n; i++) {
            if(a[i] != i+1 && a[(i+1)%n] != i+1) {
                possible = false;
                break;
            }
        }
        
        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}