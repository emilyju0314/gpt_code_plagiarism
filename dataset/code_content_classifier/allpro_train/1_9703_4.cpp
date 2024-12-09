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
const int mod=1000000007;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-4;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>int LBI(const vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>int UBI(const vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}

int main(void){
	int i,n;cin>>n;
	static llint a[1<<20]={};
	static llint ni[100001]={};
	ni[0]=1;
	for(i=0;i<n;i++){ni[i+1]=ni[i]*2%mod;}
	while(n--){
		int x;cin>>x;
		a[x]++;
	}
	for(i=0;i<20;i++){
		for(int bi=0;bi<(1<<20);bi++){
			if(bi&(1<<i)){continue;}
			a[bi]+=a[bi+(1<<i)];
		}
	}
	llint ans=0;
	
	for(int bi=0;bi<(1<<20);bi++){
		int fu=1;
		for(i=0;i<20;i++){if(bi&(1<<i)){fu*=-1;}}
		ans+=fu*ni[a[bi]];ans%=mod;
		//if(bi<16){cerr<<ni[a[bi]]<<endl;}
	}
	ans+=mod;ans%=mod;
	cout<<ans<<endl;
	return 0;
}
/*
3
0 1 2
3 1 1 0
+ - - +
8-2-2+1 =5
*/
