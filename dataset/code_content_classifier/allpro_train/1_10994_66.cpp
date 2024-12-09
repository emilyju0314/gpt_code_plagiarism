#include <bits/stdc++.h>
#define REP(i,n)for (int i=0;i<(n);i++)
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define ll long long
using namespace std;
int main(){
    int n,m,t,a;
    int time[10100];
    memset(time,0,sizeof(time));
    cin>>n>>m>>t;
    REP(i,n){
        cin>>a;
        time[a-m]++;time[min(a+m,10010)]--;
    }
    REP(i,t)time[i+1]+=time[i];
    int ans=0;
    REP(i,t)if(time[i]==0)ans++;
    cout<<ans<<endl;
}