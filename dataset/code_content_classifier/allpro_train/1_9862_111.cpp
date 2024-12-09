#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <typeinfo>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

#define dump(n) cout<<"# "<<#n<<"="<<(n)<<endl
#define debug(n) cout<<__FILE__<<","<<__LINE__<<": #"<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();i++)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main()
{
	for(int h,w;cin>>h>>w,h|w;){
		vs field(h);
		rep(i,h)
			cin>>field[i];
		vvi hist(h,vi(w));
		rep(i,w)
			if(field[0][i]=='.')
				hist[0][i]=1;
		repi(i,1,h)
			rep(j,w)
				if(field[i][j]=='.')
					hist[i][j]=hist[i-1][j]+1;
		int res=0;
		rep(i,h){
			hist[i].push_back(0);
			stack<pii> s;	// pos,height
			rep(j,hist[i].size()){
				int left=j;
				while(s.size() && s.top().second>hist[i][j]){
					left=s.top().first;
					res=max(res,s.top().second*(j-s.top().first));
					s.pop();
				}
				s.push(mp(left,hist[i][j]));
			}
		}
		cout<<res<<endl;
	}
	
	return 0;
}