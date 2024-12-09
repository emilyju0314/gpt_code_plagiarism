#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF (long long)(1e18)
#define MOD (int)(1e9+7)

#define yn(f) ((f)?"Yes":"No")
#define YN(f) ((f)?"YES":"NO")

#define EPS 1e-11

string hogehoge;

int k, r, l;
double p, e, t;

double solve(double R, double L, double T, int K){//cout<<R<<" "<<L<<" "<<K<<endl;//cin>>hogehoge;
	double H = (R+L)/2, ans = 0, P = H < t?p:1-p;
	
	if(!K){if(fabs(t-H) <= e) return 1; else return 0;}
	
	if(t-e < R && H < t+e) ans += P;
	else 
		if(t-e < H) ans += solve(R,H,H,K-1)*P;
	
	if(t-e < H && L < t+e) ans += 1-P;
	else 
		if(t+e > H) ans += solve(H,L,H,K-1)*(1-P);
	
	return ans;
	
}


signed main(){
	cout<<fixed<<setprecision(7);
	
	cin>>k>>r>>l>>p>>e>>t;
	
	cout<<solve(r,l,t,k)<<endl;
	return 0;
}
