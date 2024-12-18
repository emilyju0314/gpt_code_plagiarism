#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
#include <map>
#include <climits>
#include <sstream>
using namespace std;

#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second
#define mkp make_pair

static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
static const int INF=1<<24;

template <class T>
void initvv(vector<vector<T> > &v,int a,int b, const T  &t = T()){
	v.assign(a,vector<T>(b,t));
}

//v.erase(unique(v.begin(),v.end()),v.end());


int main(){
	int n;
	cin>>n;
	rep(i,n){
		string s;
		cin>>s;
		string ans=s.substr(0,1);
		int c=0;
		while(1){
			// cout<<s[c]<<endl;
			if(c>=s.size()-1) break;
			string t=s.substr(c+1,2);
			if(t=="->"&&ans[ans.size()-1]==s[c]){
				ans=ans+s.substr(c+3,1);
			}
			else if(t=="<-"&&ans[0]==s[c]){
				ans=s.substr(c+3,1)+ans;
			}
			c+=3;
		}
		cout<<ans<<endl;
	}
}