#include <bits/stdc++.h>
using namespace std;
int l,q,n[1<<20],m[1<<20],a,b,c,x[21],y[21],z[21],ans,p;
char s[(1<<20)+1],t[21];
int main(void){
    scanf("%d%d %s",&l,&q,s);
    for(int i=0;i<1<<l;i++){
        n[i]=s[i]-'0';
        m[i]=s[i]-'0';
    }
    for(int i=0;i<l;i++){
        for(int k=0;k<1<<l;k++){
            if((k&(1<<i))==0)n[k]+=n[k|(1<<i)];
            else m[k]+=m[k^(1<<i)];
        }
    }
    while(q--){
        scanf(" %s",t);
        a=0,b=0,c=0,ans=0,p=0;
        for(int i=0;i<l;i++){
            if(t[l-i-1]=='0')x[a++]=i;
            else if(t[l-i-1]=='1'){
                y[b++]=i;
                p+=(1<<i);
            }else z[c++]=i;
        }
        if(a<=6){
            for(int i=0;i<1<<a;i++){
                int o=p,w=0;
                for(int j=0;j<a;j++){
                    if(i>>j&1){
                        o+=(1<<x[j]);
                        w++;
                    }
                }
                if(w%2)ans-=n[o];
                else ans+=n[o];
            }
        }else if(b<=6){
            for(int i=0;i<c;i++)p+=(1<<z[i]);
            for(int i=0;i<1<<b;i++){
                int o=p,w=0;
                for(int j=0;j<b;j++){
                    if(i>>j&1){
                        o-=(1<<y[j]);
                        w++;
                    }
                }
                if(w%2)ans-=m[o];
                else ans+=m[o];
            }
        }else{
            for(int i=0;i<1<<c;i++){
                int o=p;
                for(int j=0;j<c;j++)if(i>>j&1)o+=(1<<z[j]);
                ans+=(s[o]-'0');
            }
        }
        printf("%d\n",ans);
    }
}
