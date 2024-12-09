#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N;
int a[40000],b[40000];
int cnt[40000];
int main(){
    while(scanf("%d",&N),N){
        rep(i,N)scanf("%d",&a[i]);
        rep(i,N)scanf("%d",&b[i]);
        sort(a,a+N);reverse(a,a+N);
        sort(b,b+N);reverse(b,b+N);

        memset(cnt,0,sizeof(cnt));
        int cur=0,sum=0;
        rep(i,N-1){
            while(cur<N&&a[cur]>b[i])cur++;
            
            if(cur!=N)cnt[cur++]=1;
            sum+=cnt[i];
            if(i+1-sum>sum){
                cout<<i+1<<endl;
                goto END;
            }
        }
        cout<<"NA"<<endl;

        END:;
    }
    return 0;
}