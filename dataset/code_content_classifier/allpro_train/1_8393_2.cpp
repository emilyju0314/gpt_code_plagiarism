#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m){
    vector<string> pat(n);
    for(int i=0;i<n;i++) cin>>pat[i];
    string tar;
    for(int i=0;i<m;i++){
        string buf;
        cin>>buf;
        tar+=buf;
    }
    m=tar.size();
    vector<vector<int>> isJumpable(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i+pat[j].size()>m) continue;
            isJumpable[i][j]=(pat[j]==tar.substr(i,pat[j].size()));
        }
    }
    int len=accumulate(pat.begin(),pat.end(),0,[](int lhs,string rhs){return lhs+rhs.size();});
    int res=0;
    for(int i=0;i+len<=m;i++){
        vector<vector<int>> dp(len+1);
        dp[0].push_back(0);
        vector<int> used(1<<n);
        for(int j=0;j<len;j++){
            for(auto st:dp[j]){
                if(used[st]) continue;
                used[st]=true;
                for(int k=0;k<n;k++){
                    if((st>>k)&1) continue;
                    if(isJumpable[i+j][k]){
                        dp[j+pat[k].size()].push_back(st|(1<<k));
                    }
                }                
            }
            dp[j].clear();
        }
        if(!dp[len].empty()) res++;
    }
    return res;
}
int main(){
    int n,m;
    while(cin>>n>>m,n){
        cout<<solve(n,m)<<endl;
    }
    return 0;
}
