#include	<bits/stdc++.h>
using	namespace	std;
int main(){
	int N;
	string S;
	cin>>N>>S;
	int U=0;
	for (int i=2;i<N;i++) {
		int T=0;
		for (int j=0;i+j<N;j++)
			if (S[j]==S[j+i]) U=max(U,min(i, ++T));
			else T=0;
	}
	cout<<U;
}

