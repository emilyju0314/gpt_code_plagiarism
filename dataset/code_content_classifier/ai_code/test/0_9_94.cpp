#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> denominations(n);
        for(int i = 0; i < n; i++) {
            cin >> denominations[i];
        }

        int ans = 1;
        while(true) {
            bool flag = true;
            for(int i = 0; i < n; i++) {
                if(ans % (int)pow(10, denominations[i]) == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag && ans > k) {
                break;
            }
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}