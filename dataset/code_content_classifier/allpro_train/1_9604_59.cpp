#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
 
using namespace std;
 
#define pb(n)	push_back(n)
#define mp(n,m) make_pair(n,m)
#define fi 	first
#define se 	second
#define all(r) (r).begin(),(r).end()
 
#define REP(i,s,e)	for(int i=(s); i<(e); i++)
#define rep(i,n)	REP(i,0,n)
#define REPE(i,s,e)	for(int i=s; i>e; i--)
#define repe(i,n)	REPE(i,n,-1)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
typedef vector<vi> vii;
 
const int IMAX=((1<<30)-1)*2+1;
const int INF=100000000;
const double EPS=1e-10;
//int mod=1000000007
 




int N,Q;
int c,q,mxc;
bool f;

int main(){
	while(cin>>N>>Q){
		//cout<<N<<" "<<Q<<endl;
		set<int> s;
		mxc=-1;
		rep(i,N){
			cin>>c;
			mxc=max(mxc,c);
			s.insert(c);
		}
		s.insert(0);
		for(int i=0; i<Q; i++){
			f=false;
			cin>>q;
			int qp=q;
			while(qp>0){
				for(int i=qp-1; i<=mxc; i+=q){
					if(s.count(i)){
						cout<<qp-1<<endl;
						//cout<<"i:"<<i<<endl;
						f=true;
						break;
					}
				}
				if(f) break;
				qp--;
			}
		}
	}
}



// int N,Q;
// vi c;
// int q;


// int main(){
// 	while(cin>>N>>Q){
// 		c=vi(N,0);
// 		rep(i,N) cin>>c[i];
// 		sort(all(c));

// 		rep(i,Q){
// 			cin>>q;
// 		}
// 	}

// }