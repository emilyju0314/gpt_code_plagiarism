#include<iostream>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
#define di(a) ('0'<=a&&a<='9')
#define az(a) ('A'<=a&&a<='Z')
#define INF 1ll<<40
using namespace std;
typedef unsigned long long ll;
string s; int n; ll tL[100],fL[100];
int fNext(int p){
	while(di(s[p]))p++;
	if(s[p]=='(')for(int d=0;p<n;p++){
		if(s[p]=='(')d++;
		if(s[p]==')'){
			d--; if(d==0)break;
		}
	}
	return p<n-1&&di(s[p+1])|az(s[p+1])?p+1:-1;
}
ll tLen(int p){
	if(tL[p])return tL[p];
	int m=0,fn=fNext(p),pp=p;
	while(di(s[p]))m*=10,m+=s[p++]-'0'; if(m==0)m=1;
	if(az(s[p]))tL[pp]=m+(fn<0?0:tLen(fn));
	else tL[pp]=m*(tLen(p+1))+(fn<0?0:tLen(fn));
	if(tL[pp]>=INF)tL[pp]=INF;
	return tL[pp];
}
ll fLen(int p){
	if(fL[p])return fL[p];
	int m=0,pp=p;
	while(di(s[p]))m*=10,m+=s[p++]-'0'; if(m==0)m=1;
	if(az(s[p]))return fL[pp]=m;
	fL[pp]=m*(tLen(p+1));
	if(fL[pp]>=INF)fL[pp]=INF;
	return fL[pp];
}
char ge(int p,int idx){
	int m=0,fn=fNext(p),pp=p;
	if(idx>=fLen(p))return fn<0?'0':ge(fn,idx-fLen(p));
	while(di(s[p]))m*=10,m+=s[p++]-'0'; if(m==0)m=1;
	if(s[p]=='('){
		if(fLen(pp)<INF)idx%=fLen(pp)/m;
		return ge(p+1,idx);
	}
	if(idx<m)return s[p];
	return ge(p+1,idx-m);
}
int main(){
	int idx;
	while(cin>>s>>idx,s[0]!='0'){
		rep(i,100)fL[i]=tL[i]=0;
		n=s.size();
		cout<<ge(0,idx)<<endl;
	}
	return 0;
}