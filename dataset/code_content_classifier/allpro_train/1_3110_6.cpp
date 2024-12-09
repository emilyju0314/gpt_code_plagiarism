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
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
using namespace std;
using namespace std::chrono;
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
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const llint mod=1000000007;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-10;
const long double epsA=1e-4;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(const vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(const vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}


int main(void){
	cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);
	int i,n,m;cin>>n>>m;
	vector<int>v(n);
	vector<vector<int>>go(n);
	vector<vector<int>>rev(n);
	vector<int>zi(n);
	vector<int>dim(n);//次元的な何か
	for(i=0;i<n;i++){cin>>v[i];}
	for(i=0;i<m;i++){
		int a,b;cin>>a>>b;a--;b--;
		go[a].pub(b);
		rev[b].pub(a);
		zi[a]++;
	}
	stack<int>que;
	for(i=0;i<n;i++){if(zi[i]==0){que.push(i);}}
	vector<int>gru(n+1,-1);
	while(que.size()){
		int t=que.top();que.pop();
		for(auto it:go[t]){gru[dim[it]]=t;}
		int bas=0;
		while(gru[bas]==t){bas++;}
		dim[t]=bas;
		for(auto it:rev[t]){
			zi[it]--;
			if(zi[it]==0){que.push(it);}
		}
	}
	vector<int>ans(n);
	for(i=0;i<n;i++){ans[dim[i]]^=v[i];}
	for(i=0;i<n;i++){if(ans[i]>0){cout<<1<<endl;return 0;}}
	cout<<2<<endl;
	return 0;
}

