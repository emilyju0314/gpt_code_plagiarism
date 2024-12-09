#include <bits/stdc++.h>
#define sz(c)      int(c.size())
#define rep(i,a,b) for (int i=a; i<(b); ++i)
#define per(i,a,b) for (int i=(b)-1; i>=(a); --i)
using namespace std;
using ll = long long;

vector<int> solve(int n,int a,int b) {
	if (__builtin_popcount(a^b)%2==0) return {};
	
	if (n==1) return {a,b};

	int bit=1<<(n-1);
	if ((a&bit)==(b&bit)) {
		auto r1=solve(n-1,a,b);
		auto r2=solve(n-1,a^bit,r1[1]^bit);
		r1.insert(r1.begin()+1,r2.begin(),r2.end());
		return r1;
	} else {
		auto r1=solve(n-1,a,b^1^bit);
		auto r2=solve(n-1,b^1,b);
		r1.insert(r1.end(),r2.begin(),r2.end());
		return r1;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);

	int N,A,B;
	cin>>N>>A>>B;
	
	auto res=solve(N,A,B);
	if (res.empty()) {
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
		for (int x:res) cout<<x<<" ";
		cout<<"\n";
	}
}
