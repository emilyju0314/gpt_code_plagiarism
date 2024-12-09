#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <cassert>
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
#include <iterator>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>
#include <typeinfo>

using namespace std;

#define dump(n) cerr<<"# "<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define foreach(i,c) for(iter(c) i=(c).begin();i!=(c).end();++i)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

int main()
{
	for(;;){
		vi a(6); rep(i,6) cin>>a[i];
		if(count(allof(a),0)==6) break;
		
		rep(i,3)
			a[i]+=a[i+3];
		
		vi b(3);
		rep(i,3){
			b[i]=a[i]/3;
			a[i]%=3;
		}
		int mn=*min_element(a.begin(),a.begin()+3);
		rep(i,3)
			a[i]-=mn;
		
		int res=b[0]+b[1]+b[2]+mn;
		rep(i,3) repi(j,i+1,3)
			if(a[i]==2 && a[j]==2 && b[3-i-j]>0)
				res++;
		
		cout<<res<<endl;
	}
	
	return 0;
}