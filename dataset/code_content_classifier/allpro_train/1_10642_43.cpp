//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
pair<int,int>dp[2005][2005];
string s;
int k;
pair<int,int>get_dp(int l,int r){
	if(l>r)return make_pair(0,1);
	if(l==r)return dp[l][r]=make_pair(1,1);
	if(dp[l][r].first!=-1)return dp[l][r];
	pair<int,int>p1=get_dp(l+1,r);
	pair<int,int>p2=get_dp(l,r-1);
	pair<int,int>p3=get_dp(l+1,r-1);
	int best=min(p1.first+2,p2.first+2);
	if(s[l]==s[r])best=min(best,p3.first+2);
	pair<int,int>ret(best,0);
	if(p1.first+2==best){
		ret.second+=p1.second;
	}
	if(p2.first+2==best){
		ret.second+=p2.second;
	}
	if(s[l]==s[r]&&p3.first+2==best){
		ret.second=p3.second;
	}
	ret.second=min(ret.second,inf);
	return dp[l][r]=ret;
}
signed main(){
	cin>>s;s=" "+s;cin>>k;
	for(int i=1;i<=2000;i++)for(int j=1;j<=2000;j++)dp[i][j]=make_pair(-1,-1);
	for(int l=1;l<s.size();l++)for(int r=l;r<s.size();r++)get_dp(l,r);
	if(dp[1][(int)s.size()-1].second<k){
		puts("NONE");
		return 0;
	}
	int l=1,r=(int)s.size()-1;
	string out="";
	while(1){
//		cerr<<l<<" "<<r<<" "<<k<<endl;
		if(l>=r){
			cout<<out;if(l==r)cout<<s[l]; 
			reverse(out.begin(),out.end());
			cout<<out<<endl;
			return 0;
		}
		if(s[l]==s[r]){
			out.push_back(s[l]);
			l++;r--;continue;
		}
		//two froms
		pair<int,int>dp1=dp[l+1][r];
		pair<int,int>dp2=dp[l][r-1];
		if(dp1.first<dp2.first){
			out.push_back(s[l]);
			l++;continue;
		}
		if(dp1.first>dp2.first){
			out.push_back(s[r]);
			r--;continue;
		}
		if(s[l]<s[r]){
			if(k<=dp1.second){
				out.push_back(s[l]);l++;
			}else{
				out.push_back(s[r]);r--;
				k-=dp1.second;
			}
		}else{
			if(k<=dp2.second){
				out.push_back(s[r]);r--;
			}else{
				out.push_back(s[l]);l++;
				k-=dp2.second;
			}
		}
	}
	return 0;
} 
