#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

char s[N+9];
int n;

void into(){
  scanf("%s",s+1);
  n=strlen(s+1);
}

int pre[N+9],suf[N+9];
LL ans;

void Get_ans(){
  int cnt=0;
  for (int i=1;i<=n;++i) pre[i]=pre[i-1]+(s[i]=='0');
  for (int i=n;i>=1;--i) suf[i]=suf[i+1]+(s[i]=='0');
  int flag=1;
  for (int i=1;i<=n;++i)
	if (s[i]=='1'){
	  ans+=(pre[i]+1+(i&1)>>1)+(flag?suf[i]:0);
	  flag^=1;
	}else flag=1;
  for (int i=1;i<n-pre[n];++i) ans+=n-pre[n]-i+1>>1;
}

void work(){
  Get_ans();
}

void outo(){
  printf("%lld\n",ans);
}

int main(){
  into();
  work();
  outo();
  return 0;
}