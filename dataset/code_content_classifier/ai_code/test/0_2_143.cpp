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
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        vector<int> cnt(n+2, 0);
        int mex = 0;
        for(int i=0; i<n; i++) {
            cnt[a[i]]++;
            while(cnt[mex] > 0) {
                mex++;
            }
        }

        vector<int> ans(n+1);
        int sum = accumulate(a.begin(), a.end(), 0);
        for(int i=0; i<=n; i++) {
            if(sum < i) {
                ans[i] = -1;
            } else if(cnt[i] == 0) {
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }

        int ops = 0;
        for(int i=n-1; i>=0; i--) {
            sum -= a[i];
            cnt[a[i]]--;
            int current_mex = mex;

            while(cnt[mex] > 0) {
                mex++;
            }

            while(current_mex < i && current_mex < mex) {
                ops++;
                current_mex++;
            }

            ans[i] = min(ans[i], ops);
        }

        for(int i=0; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}