#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> dp(n,0);
    dp[0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = k-1;j >= 0;j--){
            for(int p = i+1;p < n;p++){
                dp[p] = (dp[p] + dp[i]) % mod;
            }
        }
        if(s[i] == '0') k--;
    }
    cout << dp.back();
    return 0;
}