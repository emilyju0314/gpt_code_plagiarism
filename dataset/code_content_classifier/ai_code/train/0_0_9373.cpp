#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;
        
        vector<int> p(n);
        for(int i=0; i<n; i++) {
            cin >> p[i];
        }
        
        int i = -1, j = -1, k = -1;
        
        for(int x=0; x<n-2; x++) {
            if(p[x] < p[x+1] && p[x+1] > p[x+2]) {
                i = x+1;
                j = x+2;
                k = x+3;
                break;
            }
        }
        
        if(i != -1) {
            cout << "YES" << endl;
            cout << i << " " << j << " " << k << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}