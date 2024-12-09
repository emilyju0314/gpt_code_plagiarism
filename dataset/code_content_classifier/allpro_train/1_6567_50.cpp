#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
using namespace std;
 
#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,s,e) for(int i=(s); i<(e); i++)
#define pb(n) push_back((n))
#define mp(n,m) make_pair((n),(m))
#define all(r) r.begin(),r.end()
#define fi first
#define se second
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 

 
 
const int INF = 10000000;

int main(){
	int m,n;
	string s;
	while(cin>>m>>n && m > 0 && n > 0){
		vi v(m, 0);
		rep(i, m) v[i] = i + 1;
		auto it = v.begin();
		bool  f;
		for(int i = 1; i <= n; i++){
			cin>>s;
			f = true;
			if(i % 15 == 0){
				if(s != "FizzBuzz") f = false;
			}
			else if(i % 3 == 0){
				if(s != "Fizz") f = false;
			}
			else if(i % 5 == 0){
				if(s != "Buzz") f = false;
			}
			else if(i != atoi(s.c_str())) f = false;
			//if(!f) cout<<s<<" "<<i<<endl;
			if(v.size() != 1){
				if(f) it++;
				else it = v.erase(it);
				if(it == v.end()) it = v.begin();
			}
		}
		for(it = v.begin(); it != v.end(); it++){
			if(it != v.begin()) cout<<" ";
			cout<<*it;
		}
		cout<<endl;
	}
	
}