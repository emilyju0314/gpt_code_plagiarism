#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    const char *d[]={"lunch","dinner","midnight"};
    while(scanf("%d",&n),n){
        int cnt[3]={0},acnt[3]={0};
        while(n--){
            int t,m,r;
            scanf("%d%*c%d%d",&t,&m,&r);
            r-=m;
            if(r<0)r+=60;
            m+=t*60;
            if(11*60<=m&&15*60>m)t=0;
            else if(18*60<=m&&21*60>m)t=1;
            else if(21*60<=m||2*60>m)t=2;
            else continue;
            acnt[t]++;
            if(r<=8)cnt[t]++;
        }
        for(int i=0;i<3;i++){
            printf("%s ",d[i]);
            if(acnt[i]==0)printf("no guest\n");
            else printf("%d\n",100*cnt[i]/acnt[i]);
        }
    }
}