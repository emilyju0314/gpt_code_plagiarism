#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

    int t;cin>>t;
    while(t--){

        int n;cin>>n;

        int arr[n];
        int prefix[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i == 0){
                prefix[0] = arr[0];
            }
            else{
                prefix[i] = prefix[i-1]+arr[i];
            }
        }

        int m;cin>>m;

        int brr[m];
        int suffix[m];

        for(int i=0;i<m;i++){
            cin>>brr[i];
            if(i == 0){
                suffix[0] = brr[0];
            }
            else{
                suffix[i] = suffix[i-1]+brr[i];
            }
        }

        int dp[150][150];
        memset(dp,0,sizeof(dp));
        int bada = 0;

        // int i=0,j=0;
        // int sum = 0;

        // while(i<n && j<m){

        //     int val = max(arr[i],brr[j]);
        //     if(val == arr[i]){
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        //     sum += val;
        //     bada = max(bada,sum);
        // }

        // if(i<n){
        //     sum += arr[i];
        //     i++;
        //     bada = max(bada,sum);
        // }

        // if(j<m){
        //     sum += brr[j];
        //     j++;
        //     bada = max(bada,sum);
        // }

        for(int i=0;i<n;i++){
            
            int sum = prefix[i];
            for(int j=0;j<m;j++){
               // cout<<"prefix["<<i<<"] = "<<prefix[i]<<"\n";
               // cout<<"suffix["<<j<<"] = "<<suffix[j]<<"\n";
                dp[i][j] = max(dp[i][j],prefix[i]);
                dp[i][j] = max(dp[i][j],suffix[j]);
                dp[i][j] = max(dp[i][j],prefix[i]+suffix[j]);
               // cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<"\n";
               // cout<<"-------------------------------------"<<"\n";
                bada = max(bada,dp[i][j]);
            }
        }


        cout<<bada<<"\n";
        
    }
}