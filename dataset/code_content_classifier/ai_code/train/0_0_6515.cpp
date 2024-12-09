#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> dp(n);
    for(int i = 0; i < n; i++) {
        dp[i] = b[i];
        for(int j = 0; j < i; j++) {
            if(a[i] % a[j] == 0) {
                dp[i] = max(dp[i], dp[j] + b[i]);
            }
        }
    }

    int max_cost = 0;
    for(int i = 0; i < n; i++) {
        max_cost = max(max_cost, dp[i]);
    }

    cout << max_cost << endl;

    return 0;
}