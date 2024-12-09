#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define frep(i,a,b) for(int i=(a);i<(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
#define fdrep(i,a,b) for(int i=(a);i>(b);--i)
using namespace std;
ll read(){
	register ll a=0,b=1;
	register char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')b=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar()*b;
	}
	return a*b;
}
#define Qmin priority_queue<int,vector<int> ,less<int> >
#define Qmax priority_queue<int,vector<int> ,greater<int> >
int mylog(int a){
	int ans=0;
	if(a&0xffff0000){ans+=16;a>>=16;}
	if(a&0x0000ff00){ans+=8;a>>=8;}
	if(a&0x000000f0){ans+=4;a>>=4;}
	if(a&0x0000000c){ans+=2;a>>=2;}
	if(a&0x00000002){ans+=1;a>>=1;}
	return ans;
}
const int N=2e3;
char s[100];
int main(){
	int t=read();
	while(t--){
		scanf("\n%s",s);
		int len=strlen(s);
		frep(i,0,len){
			if(i&1){
				if(s[i]=='z')s[i]='y';
				else s[i]='z';
			}
			else{
				if(s[i]=='a')s[i]='b';
				else s[i]='a';
			}
		}
		printf("%s\n",s);
	}
	return 0;
	
}
