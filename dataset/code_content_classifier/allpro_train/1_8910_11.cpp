#include<cstdio>
#include<string>

#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

typedef	unsigned long long	ull;

ull nCr[61][61];

string solve(int n,int num1,ull m){
	if(num1==0)	return string(n,'0');
	if(num1==n)	return string(n,'1');

	if(m<=nCr[n-1][num1])	return '0'+solve(n-1,num1,m);
	else					return '1'+solve(n-1,num1-1,m-nCr[n-1][num1]);
}

int main(){
	rep(n,61)	nCr[n][0]=1;
	for(int n=1;n<61;n++)rep(r,n+1)	nCr[n][r]=nCr[n-1][r]+nCr[n-1][r-1];

	int n; ull m;
	while(scanf("%d%llu",&n,&m),n){
		int num1;
		for(int i=0;;i++){
			if(m<=nCr[n][i]){ num1=i; break; }
			m-=nCr[n][i];
		}
		puts(solve(n,num1,m).c_str());
	}

	return 0;
}