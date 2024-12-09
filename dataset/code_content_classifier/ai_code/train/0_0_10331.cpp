#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ans;
    for(int i = 1; i <= n; i *= 2) {
        ans.push_back(i);
    }

    int remaining = n - (1 <<  __builtin_ctz(n));
    if(remaining > 0) {
        ans[remaining - 1] *= 2;
    }

    cout << ans.size() << endl;
    for(int i : ans) {
        cout << i << " ";
    }
    
    return 0;
}