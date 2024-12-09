#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> ans;
    for(int b = 0; b <= 5000; b++) {
        vector<bool> dp(b+1);
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            for(int j = b; j >= a[i]; j--) {
                dp[j] |= dp[j - a[i]];
            }
        }
        if(dp[b]) {
            ans.insert(b);
        }
    }

    cout << ans.size() << endl;
    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}