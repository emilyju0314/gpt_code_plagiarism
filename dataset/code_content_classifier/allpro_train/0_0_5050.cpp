#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int longestGoodSequence(vector<int> a) {
    int n = a.size();
    vector<int> dp(n, 1);
    int ans = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (gcd(a[i], a[j]) != 1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << longestGoodSequence(a) << endl;
    
    return 0;
}