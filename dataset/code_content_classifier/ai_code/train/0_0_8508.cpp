#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, ans = 0;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = n-2; i >= 0; i--) {
            if(i + a[i] < n-1) {
                a[i] = min(n-1, a[i]);
                ans += (a[i] == 0) ? 1 : 0;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}