#include <iostream>
#include <vector>

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

        long long ans = 1;
        for(int i = 1; i < k; i++) {
            bool flag = false;
            for(int d : denominations) {
                if(ans % (1 << d) == 0) {
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                break;
            }
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}