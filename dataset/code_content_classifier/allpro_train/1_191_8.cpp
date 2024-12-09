/*
~2021~
*/
# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
#define pii pair<int,int>
const int N = 1e7 ;
const int INF = 1e9;
const ll mod = 1e9+7;
int primeterkecil[N + 5],ans[N + 5];
ll sum[N + 5];
void sieve(){
    primeterkecil[1] = 1;
    for(int i = 2;i * i<=N;i++){
        if(primeterkecil[i] != 0) continue;
        primeterkecil[i] = i;
        for(int j = i * i;j<=N;j += i){
            if(primeterkecil[j] == 0) primeterkecil[j] = i;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(,r,stdin);
    //freopen(,w,stdout);
    sieve();
    for(int i = 1;i<=N;i++) sum[i] = 1;
    for(int i = 2;i<=N;i++){
        if(primeterkecil[i] == 0){
            primeterkecil[i] = i;
            sum[i] = i + 1;
        }
        else{
            int temp = i;
            while(temp % primeterkecil[i] == 0){
                //cout<<temp<<endl;
                temp/=primeterkecil[i];
                sum[i] = sum[i] * primeterkecil[i] + 1;
            }
            sum[i] *= sum[temp];

        }
    }
    memset(ans,-1,sizeof(ans));
    for(int i = 1;i<=N;i++){
        if(sum[i] <= N && ans[sum[i]] == -1) ans[sum[i]] = i;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<'\n';
    }
}