#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> dp(n+1, -1);
    vector<int> parent(n+1, -1);

    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for(int i=1; i<=n; i++) {
        cin >> b[i];
    }

    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i; j>=1; j--) {
            if(dp[j] != -1 && j + a[j] >= i) {
                if(dp[i] == -1 || dp[i] > dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }
        if(dp[i] != -1) {
            i -= b[i];
        }
    }

    if(dp[n] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> jumps;
        int current = n;
        while(current > 0) {
            jumps.push_back(current);
            current = parent[current];
        }
        cout << jumps.size() << endl;
        for(int i=jumps.size()-1; i>=0; i--) {
            cout << jumps[i] << " ";
        }
    }

    return 0;
}