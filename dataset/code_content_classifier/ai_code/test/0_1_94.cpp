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
        for(int i = 1; i < k; i++) {
            bool flag = true;
            for(int j = 0; j < n; j++) {
                if(i % (int)pow(10, denominations[j]) == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}