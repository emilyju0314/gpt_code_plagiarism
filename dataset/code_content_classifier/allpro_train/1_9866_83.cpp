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
typedef pair<LL,LL> P;
const LL LINF=1LL<<62;
const LL mod=1e9;


const int M_N=1000000;
bool prime[M_N+1];
 
void Sieve(){
    int i,j;
    prime[1]=false;
    for (i=2;i*i<=M_N;i++){
        if (prime[i]==true){
            for (j=2;i*j<=M_N;j++){
                prime[i*j]=false;
            }
        }
    }
}

int a[4001][4001];

void dfs(int i,int x,int y,int count,int sum){
    if(i%2==0) count++;
    for(int s=0;s<count;s++){
        if(i%4==0) a[y][++x]=++sum;
        if(i%4==1) a[--y][x]=++sum;
        if(i%4==2) a[y][--x]=++sum;
        if(i%4==3) a[++y][x]=++sum;
        if(sum==1000000) return;
    }
    dfs((i+1)%4,x,y,count,sum);
}

void check(int *x,int *y,int n){
    for(int i=-1000;i<=1000;i++){
        for(int j=-1000;j<=1000;j++){
            if(a[2000+i][2000+j]==n){
                *y=i+2000;
                *x=j+2000;
                return;
            }
        }
    }
}

int dp[4000][4000];

int main(){
    memset(prime,true,sizeof(prime));
    Sieve();
    int m,n;
    a[2000][2000]=1;
    dfs(0,2000,2000,0,1);
    while(cin >> m >> n){
        if(m==0&&n==0) return 0;
        memset(dp,0,sizeof(dp));
        int x,y;
        check(&x,&y,n);
        int c=1;
        dp[y][x]=prime[a[y][x]];
        int ans=dp[y][x],p=0;
        if(ans>0) p=a[y][x];
        for(int i=y;i<=y+1000;i++){
            for(int j=-c+x;j<=x+c;j++){
                if(a[i+1][j]==0||a[i+1][j]>m) continue;
                dp[i+1][j]=max({dp[i][j-1],dp[i][j],dp[i][j+1]})+prime[a[i+1][j]];
                if(ans<dp[i+1][j]){
                    ans=dp[i+1][j];
                    p=a[i+1][j];
                }
                else if(ans==dp[i+1][j]&&a[i+1][j]>p&&prime[a[i+1][j]]){
                    p=a[i+1][j];
                }
            }
            c++;
        }
        cout << ans <<" "<< p << endl;
    }
    return 0;
}
