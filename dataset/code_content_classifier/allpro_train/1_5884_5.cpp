#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define All(A) A.begin(),A.end()
#define RAll(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;
const LL INF=1<<30;


LL f[2][1000005];
    LL s[4][1000005],t[4][1000005];


bool check(LL x,LL a,int N){
    LL imos[N+3];
    memset(imos,0,sizeof(imos));
    for(int i=1;i<=N;i++){
        if(x<=f[1][i]){
            imos[1]++;
            imos[N+1]--;
            continue;
        }
        else if(a+f[1][i]-x<0){
            return false;
        }
        LL u=(LL)sqrt(a+f[1][i]-x);
        imos[max(i-u,1LL)]++;
        imos[min((LL)N+1,i+u+1)]--;
    }
    LL sum=0;
    for(int i=1;i<=N+1;i++){
        sum+=imos[i];
        if(sum==N) return true;
    }
    return false;
}



int main(){
    int N,M;
    while(cin >> N >> M){
        if(N==0&&M==0) break;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        memset(f,0,sizeof(f));
        for(int i=0;i<M-1;i++){
            LL a,x;
            cin >> a >> x;
            LL tm=min(N-x,(LL)sqrt(a));
            t[0][x+tm+1]-=2;
            t[0][x+1]+=1;
            t[0][x+2]+=1;
            t[1][x+tm+1]-=2*tm-1;
            t[2][x+tm+1]-=tm*tm;
            LL sm=min((LL)sqrt(a),x-1);
            s[0][x-sm-1]-=2;
            s[0][x-1]+=1;
            s[0][x-2]+=1;
            s[1][x-sm-1]-=2*sm-1;
            s[2][x-sm-1]-=sm*sm;
            f[0][x+tm+1]-=a;
            f[0][x-sm]+=a;
        }
        for(int i=0;i<3;i++){
            LL sum=0;
            for(int j=1;j<=N+1;j++){
                sum+=t[i][j];
                t[i+1][j]+=sum;
            }
            sum=0;
            for(int j=N;j>=0;j--){
                sum+=s[i][j];
                s[i+1][j]+=sum;
            }
        }
        LL sum=0;
        for(int i=1;i<=N;i++){
            sum+=f[0][i];
            f[1][i]+=sum;
            f[1][i]-=t[3][i]+s[3][i];
        }
        LL a;
        cin >> a;
        LL l=0,r=LINF;
        while(l+1!=r&&l!=r){
            LL m=(l+r)/2;
            if(check(m,a,N)) l=m;
            else r=m;
        }
        cout << l << endl;
    }
    return 0;
}
