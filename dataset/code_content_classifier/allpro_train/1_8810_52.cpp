#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using mat = vector<vector<LL>>;
const LL mod=1e9+7;

mat matmul(mat &A, mat &B){
	mat C(A.size(),vector<LL>(B[0].size()));
	rep(i,A.size()){
		rep(k,B.size()){
			rep(j, B[0].size()){
				(C[i][j]+=A[i][k]*B[k][j])%=mod;
			}
		}
	}
	return C;
}

mat matpow(mat A, LL n){
	mat C(A.size(),vector<LL>(A.size()));
	rep(i,A.size()) C[i][i]=1;
	while(n>0){
		if(n&1) C=matmul(C,A);
		A=matmul(A,A);
		n>>=1;
	}
	return C;
}

int main(){
	int N;
	cin >> N;
	LL K;
	cin >> K;
	mat a(N,vector<LL>(N));
	rep(i,N){
		rep(j,N) cin >> a[i][j];
	}
	mat b=matpow(a,K);
	LL ans=0;
	rep(i,N){
		rep(j,N) (ans+=b[i][j])%=mod;
	}
	cout << ans << endl;

	return 0;
}