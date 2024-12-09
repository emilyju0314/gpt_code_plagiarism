#include <bits/stdc++.h>
#define N 2005
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int gets(){
    int v=0; char ch; bool f=0;
    while(!isdigit(ch=getchar())) if(ch=='-') f=1; v=ch-48;
    while( isdigit(ch=getchar())) v=(v<<3)+(v<<1)+ ch-48;
    return f?-v:v; 
}
char ch[N];
int T,n,m,ans[15],t,v,lef[15],rig[15],upp[15],dwn[15],flag[N],a[N][N];
int main(){
    T=gets();
    while(T--){
        n=gets();
        rep(i,0,9) lef[i]=upp[i]=n+1, rig[i]=dwn[i]=-1, ans[i]=0; 

        rep(i,1,n) {
            scanf("%s",ch+1); 
            rep(j,1,n){
                v=a[i][j]=ch[j] - '0';  
                upp[v]=min(i,upp[v]);
                dwn[v]=max(i,dwn[v]);
                lef[v]=min(j,lef[v]);
                rig[v]=max(j,rig[v]);

            }
        }
        rep(i,1,n){
            rep(j,1,n){
                v = a[i][j]; 
                t = max(i-1,n-i);
                ans[v]=max(ans[v],t*max(j-lef[v],rig[v]-j));
                t = max(j-1,n-j);
                ans[v]=max(ans[v],t*max(i-upp[v],dwn[v]-i));
            }
        }
        rep(i,0,8) printf("%d ",ans[i]); 
        printf("%d\n",ans[9]); 

    }
    return 0; 
}
		    	     	  	 	   			 			