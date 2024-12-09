#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MP make_pair
#define UM unordered_map
typedef long long ll;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const ll INF=1e18;
#define pi 3.1415926535898
#define DEC (pi/180)
const static int M=1e5+5;
ll x[M],y[M];
void pn(){
    puts("NO");
}
void py(){
    puts("YES");
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
        }
        int nowi=1;
        ll las=0;
        int ans=0;
        while(nowi<=n){
            int j=nowi;
            if(j==n){
                ans++;
                break;
            }
            nowi++;
            ll nowti=0;
            while(nowi<=n&&x[nowi]-x[j]<abs(las-y[j])){
                ll tmp=nowti;
                nowti+=x[nowi]-x[nowi-1];
                if(las<y[j]){
                    if(las+tmp<=y[nowi-1]&&y[nowi-1]<=y[j]&&y[nowi-1]-las<=nowti)
                        ans++;
                }
                else{
                    if(y[j]<=y[nowi-1]&&y[nowi-1]<=las-tmp&&las-y[nowi-1]<=nowti)
                        ans++;
                }
                nowi++;
            }
           /// cout<<ans<<"!!!"<<endl;
            ll tmp=nowti;
            nowti+=abs(las-y[j])-(x[nowi-1]-x[j]);

            if(las<y[j]){
                if(las+tmp<=y[nowi-1]&&y[nowi-1]<=y[j]&&y[nowi-1]-las<=nowti)
                    ans++;
            }
            else{
                if(y[j]<=y[nowi-1]&&y[nowi-1]<=las-tmp&&las-y[nowi-1]<=nowti)
                    ans++;
            }
            las=y[j];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
