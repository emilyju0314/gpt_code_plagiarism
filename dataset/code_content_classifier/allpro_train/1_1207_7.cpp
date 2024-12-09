#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;


long long int mod=1e9+7;

int main() {
	int N,M;cin>>N>>M;
	vector<long long int>v(5*N);
	int k=2*N;
	int x=2*N;
	v[k]=1;
	long long int sum=1;
	for (int i = 0; i < N; ++i) {
		k--;
		v[k]=sum;
		sum+=sum;
		if (i >= M - 1) {

			sum -= v[x];
			v[x] = 0;
			x--;

		}
		sum+=mod*10;
		sum%=mod;
	}
	long long int pown=1;
	for (int k = 0; k < N; ++k) {
		pown*=2;
		pown%=mod;
	}
	long long int ans=pown+mod*1000000-(accumulate(v.begin(),v.end(),0ll));
	ans%=mod;
	cout<<ans<<endl;
	
		return 0;
}
