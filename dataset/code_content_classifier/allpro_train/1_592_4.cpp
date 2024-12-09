#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<char,LL> P;
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<30;

vector<vector<int>> nextIndex(const string &s){
    int n = s.length();
    vector<vector<int>> ret(n+1,vector<int> (2,n));
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 2; j++) ret[i][j] = ret[i+1][j]; 
        ret[i][s[i] - '0'] = i;
    }
    return ret;
}


int main(){
    string s,t;cin >> s >> t;
    auto p = nextIndex(s);
    auto q = nextIndex(t);
    int sn = s.length(),tn = t.length();
    vector<vector<int>> dp(sn+2,vector<int> (tn+2,INF));
    vector<vector<pair<char,pair<int,int>>>> recon(sn+2,vector<pair<char,pair<int,int>>>(tn+2,mp('0',mp(sn,tn))));
    dp[sn+1][tn+1] = 0;
    dp[sn][tn] = 1;
    for (int i = sn+1; i >= 0; i--) {
        for (int j = tn+1; j >= 0; j--) {
            if(i==sn+1&&j==tn+1) continue;
            for (int k = 0; k < 2; k++) {
                int ni,nj;
                if(i>=sn) ni = sn; else ni = p[i][k];
                if(j>=tn) nj = tn; else nj = q[j][k];
                if(dp[i][j] > dp[ni+1][nj+1]+1){
                    dp[i][j] = dp[ni+1][nj+1]+1;
                    recon[i][j] = mp('0'+k,mp(ni+1,nj+1));
                }
            }
        }
    }
    int i=0,j=0;
    string ans="";
    for (int k = 0; k < dp[0][0]; k++) {
        auto st = recon[i][j];
        ans += st.fs;
        i = st.sc.fs;
        j = st.sc.sc;
    }
    cout << ans << endl;
    return 0;
}

