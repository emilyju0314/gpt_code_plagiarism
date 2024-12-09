#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

const int LIM=1<<16;
bool sosu[LIM];

int main() {
	int i,j;
	for(i=0;i<LIM;i++)sosu[i]=true;
	sosu[0]=sosu[1]=false;
	for(i=0;i<LIM;i++){
		if(sosu[i]){
			for(j=i*2;j<LIM;j+=i){
				sosu[j]=false;
			}
		}
	}
	int n;
	while(n=in()){
		int res=0;
		for(i=0;i<=n/2;i++){
			if(sosu[i]&&sosu[n-i])res++;
		}
		cout<<res<<endl;
	}
	return 0;
}