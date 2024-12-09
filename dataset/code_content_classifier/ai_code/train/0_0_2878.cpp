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

        int xr = 0;
        for(int i = 0; i < n; i++) {
            xr ^= a[i];
        }

        if(xr == 0) {
            cout << "YES" << endl;
        } else {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if((xr ^ a[i]) == a[i]) {
                    cnt++;
                }
            }
            if(cnt >= 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}