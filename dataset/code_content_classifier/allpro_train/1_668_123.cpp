#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define db double
#define pint pair<int,int>
#define mk(x,y) make_pair(x,y)
#define fir first
#define sec second
#define Rep(x,y,z) for(int x=y;x<=z;x++)
#define Red(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
const int MAXN=1e5+5,Mod=1e9+7;
char buf[1<<12],*p1=buf,*p2=buf,nc;int ny;
inline char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
//inline char gc(){return getchar();}
inline int read(){
	int x=0;for(ny=1;nc=gc(),(nc<48||nc>57)&&nc!=EOF;)if(nc==45)ny=-1;if(nc<0)return nc;
	for(x=nc-48;nc=gc(),47<nc&&nc<58&&nc!=EOF;x=(x<<3)+(x<<1)+(nc^48));return x*ny;
}char s[MAXN];int n,nxt[2][MAXN],F[MAXN],Sum,flg;
int main(){
	scanf("%s",s+1),n=strlen(s+1),flg=1;
	Rep(i,1,n)if(s[i]==s[i+1])flg=0;if(flg){puts("1");return 0;}
	F[n+1]=1,nxt[0][n+1]=nxt[1][n+1]=nxt[0][n+2]=nxt[1][n+2]=n+2;
	Red(i,n,1){
		(Sum+=(s[i]-'a'+1))%=3;
		nxt[0][i]=s[i]=='a'?i+1:s[i+1]=='b'?i+2:nxt[0][i+2];
		nxt[1][i]=s[i]=='b'?i+1:s[i+1]=='a'?i+2:nxt[1][i+2];
		F[i]=(F[nxt[0][i]]+F[nxt[1][i]]+(Sum==0))%Mod;
	}cout<<(F[1]-(Sum==0))<<'\n';
	return 0;
}


