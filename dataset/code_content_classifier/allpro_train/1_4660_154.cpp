#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c; cin>>a>>b>>c;
	cout<<min({a*b*(c%2),a*c*(b%2),b*c*(a%2)})<<'\n';
	return 0;
}
