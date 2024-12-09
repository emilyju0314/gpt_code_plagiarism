// D - Lucky PIN
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; string S; cin>>N>>S;
	int ans = 0;
	for(int i=0; i<1000; i++){
		int j = -1;
		for(int d=100; d; d/=10){
			char c = i/d%10+'0';
			for(++j; j<N && S[j]!=c; j++);
			if(j==N) break;
			if(d==1) ans++;
		}
	}
	cout<< ans <<endl;
}