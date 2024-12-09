#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        int a = 2;
        int b = n - 2;
        
        string ans = "";
        for(int i = 1; i <= n; i++) {
            if(k > b*(b - 1)/2) {
                ans += 'b';
                k -= b*(b - 1)/2;
                b--;
            } else {
                ans += 'a';
                if(k == 1) {
                    for(int j = 1; j <= b; j++) {
                        ans += 'a';
                    }
                    ans += 'b';
                    b--;
                    break;
                }
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}