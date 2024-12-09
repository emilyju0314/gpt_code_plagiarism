#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define eb pb
#define rep(X,Y) for(int X=0;X<(Y);++X)
#define reps(X,O,Y) for(int X=O;X<(Y);++X)
#define all(X) (X).begin(),(X).end()

using namespace std;
using ll=long long;

const int N=11234567;
int prime[N];

int main(){
	fill(prime,prime+N,1);
	prime[0]=prime[1]=0;
	rep(i,N)if(prime[i])for(int j=i+i;j<N;j+=i) prime[j]=0;
	// rep(i,10) cout<<prime[i];cout<<endl;
	int n;
	cin>>n;
	if(n<=2){ cout<<0<<endl; return 0;}
	int re=0;
	reps(i,3,n+1)if(prime[i] && prime[i+2]) ++re;
	cout<<re*2<<endl;
}

