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

        vector<int> freq(n+1, 0);
        for(int i = 0; i < n; i++) {
            if(a[i] < n) {
                freq[a[i]]++;
            }
        }

        vector<int> ans(n+1, -1);
        int mex = 0;
        for(int i = 0; i < n; i++) {
            if(freq[mex] == 0) {
                ans[mex] = i+1;
            } else {
                freq[a[i]]--;
            }
            while(freq[mex] != 0) {
                freq[mex] = 0;
                mex++;
            }
        }
        ans[n] = n;

        for(int i = 0; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}