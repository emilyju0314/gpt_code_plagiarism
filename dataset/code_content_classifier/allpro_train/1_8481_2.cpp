#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long Int;

Int gcd(Int a,Int b){
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}

Int lcm(Int a,Int b){
	return a*b/gcd(a,b);
}

int M,N,A,B,C,D;

Int calc(Int x,Int y){
	if(x==0) return 1;
	if(x%y==0) return 1;
	Int d=gcd(x,y);
	return y/d;
}

bool exi[100100];
Int getminS(Int a,Int c,Int m){
	for(int i=0;i<m;i++) exi[i]=false;
	int cur=0;
	while(true){
		if(exi[cur]) break;
		exi[cur]=true;
		cur+=a;
		cur%=m;
	}
	for(Int i=1;;i++){
		Int cur=(i*c)%m;
		if(exi[cur]) return i;
	}
	return -1;
}

Int getminL(Int a,Int c,Int m){
	c%=m;
	for(int i=1;;i++){
		Int cur=(a*i)%m;
		if(cur==c) return i;
	}
	return -1;
}

Int solve(){
	if(M==1&&N==1) return 0;
	Int s1=getminS(A,C,M);
	Int s2=getminS(B,D,N);
	Int s=lcm(s1,s2);
	Int l1=getminL(A,s*C,M);
	Int l2=getminL(B,s*D,N);
	Int dl1=calc(A,M);
	Int dl2=calc(B,N);
	Int d=gcd(dl1,dl2);
	Int coe=l1-l2;
	if(coe<0) coe*=-1;
	Int k=calc(coe,d);
	
	Int t=lcm(dl1,dl2);
	
	return t*k*s-1;
}

int main(){
	cin>>M>>N>>A>>B>>C>>D;
	Int ans=solve();
	cout<<ans<<"\n";
	return 0;
}