#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define fr first
#define sc second

const int INF=1000000000;

struct SEG{
    int siz;
    int s[1<<18];
    void init(){
        siz = 1<<17;
        for(int i=0;i<2*siz-1;i++){
            s[i]=INF;
        }
    }
    void updata(int a,int b,int x,int k,int l,int r){
        if(b <= l || r <= a)return;
        if(a <= l && r <= b){
            s[k] = min ( s[k] , x );
            return;
        }
        updata(a,b,x,2*k+1,l,(l+r)/2);
        updata(a,b,x,2*k+2,(l+r)/2,r);
    }
    void _updata(int a,int x,int k,int l,int r){
        if(a+1 <= l || r <= a)return;
        if(a==l&&r==a+1){
            s[k] = x;
            return;
        }
        updata(l,r,s[k],2*k+1,l,(l+r)/2);
        updata(l,r,s[k],2*k+2,(l+r)/2,r);
        s[k] = INF;
        _updata(a,x,2*k+1,l,(l+r)/2);
        _updata(a,x,2*k+2,(l+r)/2,r);
    }
    int query(int a){
        a += siz-1;
        int ret = s[a];
        while(a > 0){
            a = (a-1)/2;
            ret = min ( ret , s[a] );
        }
        return ret;
    }
}dp[2];

int main(){
    int T;
    scanf("%d",&T);
    for(int test=0;test<T;test++){
        static int n,m,k;
        static int h[100010],x[100010];
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<m;i++){
            scanf("%d%d",&h[i],&x[i]);
        }
        
        pair<int,int> p[100010];
        for(int i=0;i<m;i++){
            p[i]=pair<int,int>(h[i],x[i]);
        }
        sort(p,p+m);
        
        dp[0].init();
        dp[1].init();
        dp[0].updata(k,n+1,-k,0,0,dp[0].siz);
        dp[1].updata(1,k+1,k,0,0,dp[1].siz);
        
        int t=0;
        int now=k;
        for(int i=0;i<m;i++){
            int c[2] = {1,-1};
            if(p[i].sc == now)now++;
            else if(p[i].sc+1 == now)now--;
            for(int j=0;j<2;j++){
                int memo=dp[j].query(p[i].sc);
                dp[j]._updata(p[i].sc,min(dp[j].query(p[i].sc+1)+c[j],abs(now-p[i].sc)-p[i].sc*c[j]),0,0,dp[j].siz);
                dp[j]._updata(p[i].sc+1,min(memo-c[j],abs(now-p[i].sc-1)-(p[i].sc+1)*c[j]),0,0,dp[j].siz);
            }
            
            if(i+1<m&&p[i].fr==p[i+1].fr)continue;
            for(;t<=i;t++){
                dp[0].updata(p[t].sc+1,n+1,min(dp[0].query(p[t].sc+1),dp[1].query(p[t].sc+1)-2*(p[t].sc+1)),0,0,dp[0].siz);
                //dp[1].updata(1,p[t].sc+2,min(dp[0].query(p[t].sc+1)+2*(p[t].sc+1),dp[1].query(p[t].sc+1)),0,0,dp[0].siz);
                //dp[0].updata(p[t].sc,n+1,min(dp[0].query(p[t].sc),dp[1].query(p[t].sc)-2*p[t].sc),0,0,dp[1].siz);
                dp[1].updata(1,p[t].sc+1,min(dp[0].query(p[t].sc)+2*p[t].sc,dp[1].query(p[t].sc)),0,0,dp[1].siz);
                dp[0].updata(p[t].sc-1,n+1,min(dp[0].query(p[t].sc-1),dp[1].query(p[t].sc-1)-2*(p[t].sc-1)),0,0,dp[0].siz);
                //dp[1].updata(1,p[t].sc,min(dp[0].query(p[t].sc-1)+2*(p[t].sc-1),dp[1].query(p[t].sc-1)),0,0,dp[0].siz);
                //dp[0].updata(p[t].sc+2,n+1,min(dp[0].query(p[t].sc+2),dp[1].query(p[t].sc+2)-2*(p[t].sc+2)),0,0,dp[1].siz);
                dp[1].updata(1,p[t].sc+3,min(dp[0].query(p[t].sc+2)+2*(p[t].sc+2),dp[1].query(p[t].sc+2)),0,0,dp[1].siz);
            }
        }
        
        for(int i=1;i<=n;i++){
            printf("%d%c",min(dp[0].query(i)+i,dp[1].query(i)-i),10);
        }
    }
}