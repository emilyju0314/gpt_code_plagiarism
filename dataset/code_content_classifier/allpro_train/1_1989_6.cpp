#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
 
vector<map<P,int>> m(15);
int c[4][6]={
    {3,0,1,2,4,5},
    {1,2,3,0,4,5},
    {4,1,5,3,2,0},
    {5,1,4,3,0,2}
};

void rec(int k,int i,int y,int x,string s,vector<int> v){
    m[i][{y,x}]=v[0];
    if(s.length()==k) return;
    vector<int> t(6);
    if(s[k]=='L'){
        for (int j = 0; j < 6; j++) {
            t[j]=v[c[0][j]];
        }
        rec(k+1,i,y,x-1,s,t);
    }
    else if(s[k]=='R'){
        for (int j = 0; j < 6; j++) {
            t[j]=v[c[1][j]];
        }
        rec(k+1,i,y,x+1,s,t);
    }
    else if(s[k]=='F'){
        for (int j = 0; j < 6; j++) {
            t[j]=v[c[2][j]];
        }
        rec(k+1,i,y-1,x,s,t);
    }
    else{
        for (int j = 0; j < 6; j++) {
            t[j]=v[c[3][j]];
        }
        rec(k+1,i,y+1,x,s,t);
    }
}



int main(){
    int n;
    while(cin >> n,n){
        m.clear();
        m.resize(16);
        for (int i = 0; i < n; i++) {
            int x,y;cin >> x >> y;
            vector<int> u(6);
            cin >> u[3] >> u[1] >> u[4] >> u[5] >> u[0] >> u[2];
            string ss;cin >> ss;
            rec(0,i,y,x,ss,u);
        }
        vector<int> dp((1<<n)+1,-INF);
        dp[0]=0;
        int ans=-INF;
        for (int bit = 0; bit < 1<<n; bit++) {
            ans=max(ans,dp[bit]);
            for (int i = 0; i < n; i++) {
                if(bit&(1<<i)) continue;
                int sum = 0;
                for (auto p:m[i]) {
                    P t=p.first;
                    bool f=true;
                    for (int j = 0; j < n; j++) {
                        if(bit&(1<<j)){
                            if(m[j].find(t)!=m[j].end()){
                                f=false;
                                break;
                            }
                        }
                    }
                    if(f) sum+= p.second;
                }
                int nx = bit|(1<<i);
                dp[nx]=max(dp[nx],dp[bit]+sum);
            }
        }
        cout << ans << endl;
    }

    return 0;
}

