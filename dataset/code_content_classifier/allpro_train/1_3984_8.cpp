#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*
cout<<fixed<<setprecision(20);
cin.tie(0);
ios::sync_with_stdio(false);
*/
const llint mod=1000000007;
const llint big=2.19e18+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
vector<llint>X;
vector<vector<int>>go;
pair<vector<llint>,llint>dfs(int ter,int per){
	llint ofset=X[ter];
	vector<llint>ans(2);
	int i,j;
	for(auto it:go[ter]){
		if(it==per){continue;}
		auto ret=dfs(it,ter);
		ofset+=ret.sec;
		//ここでマージする、本当は凸性を使ったマージができるが、O(n^2)が間に合うし、凸性使ってもO(n^2)ので使わない
		vector<llint>iti(ans.size()+ret.fir.size()-1,big);
		for(i=0;i<ans.size();i++){
			for(j=0;j<ret.fir.size();j++){
				mineq(iti[i+j],ans[i]+ret.fir[j]);
			}
		}
		ans=move(iti);
	}
	for(i=0;i<ans.size();i++){ans[i]+=abs(ofset-i);}
	return mp(ans,ofset);
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,i;cin>>n;
	X.res(n);
	go.res(n);
	llint wa=0;
	for(i=0;i<n;i++){cin>>X[i];wa+=X[i];}
	for(i=0;i<n;i++){X[i]-=wa/n;}
	for(i=0;i<n-1;i++){
		int u,v;cin>>u>>v;u--;v--;
		go[u].pub(v);
		go[v].pub(u);
	}
	cout<<dfs(0,-1).fir[wa%n]<<endl;
	return 0;
}
