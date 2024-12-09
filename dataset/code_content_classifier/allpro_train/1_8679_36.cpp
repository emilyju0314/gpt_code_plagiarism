#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 1012
int n,m,tot,q[N],st[N],tp=0,st1[N],tp1=0;string ans,rp,s0[N>>2],s1[N>>2];
inline bool Ask(int x,string v){cout<<x<<" "<<v<<endl;fflush(stdout);cin>>rp;return (rp=="yes")?1:0;}
string Dec(string v){for(int i=v.length()-1;i>=0;i--)if(v[i]=='0')v[i]='1';else{v[i]='0';break;}return v;}
void Dich(int l,int r)
{
	if(!m)return;n=r-l+1;int i,x,l1=tot+1,r1,la;string now="";tp=0;
	for(i=l;i<=r;i++)
	{
		x=q[i];while(tp){if(Ask(x,ans+now+s1[m-tp])){--tp;now.erase(--now.end());continue;}if(tp==m)goto B;goto A;}
		A:st[++tp]=x;now+=(Ask(x,ans+now+'0'+s1[m-tp])?'1':'0');B:;
	}
	for(la=tp,i=tp-1;i>=1;i--)if(Ask(x=st[i],ans+now+s1[m-la])){la=i;while(now.length()>i)now.erase(--now.end());}
	for(i=1;i<=la;i++)q[++tot]=st[i];r1=tot;ans+=now;m-=la;Dich(l1,r1);
}
int main(){
	for(int i=1;i<(N>>2);i++)s0[i]=s0[i-1]+'0',s1[i]=s1[i-1]+'1';
	scanf("%d%d",&n,&m);int i;for(i=1;i<=n;i++)q[++tot]=i;Dich(1,n);cout<<0<<" "<<ans;fflush(stdout);return 0;
}