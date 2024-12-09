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

        sort(a.begin(), a.end());

        vector<int> prefix(n+1, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            prefix[min(a[i], n)]++;
        }

        int ans = 0;
        for(int i = 0; i <= n; i++) {
            if (prefix[i] == 0) {
                ans = i;
                break;
            }
            cnt += prefix[i];
        }

        vector<int> res(n+1, -1);
        int sum = 0;
        for(int i = 0; i <= n; i++) {
            res[n-sum] = ans+i;
            sum += (prefix[i] > 0);
        }

        for(int i = 0; i <= n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    return 0;
}