#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n, maxb, t;
    cin >> k >> n >> maxb >> t;
    
    for(int i=0; i<k; i++){
        vector<int> b(n);
        for(int j=0; j<n; j++){
            cin >> b[j];
        }
        
        vector<int> dp(n*t, 1);
        for(int j=0; j<n*t; j++){
            for(int l=0; l<j; l++){
                if(b[j%n] > b[l%n]){
                    dp[j] = max(dp[j], dp[l]+1);
                }
            }
        }
        
        int ans = *max_element(dp.begin(), dp.end());
        cout << ans << endl;
    }
    
    return 0;
}