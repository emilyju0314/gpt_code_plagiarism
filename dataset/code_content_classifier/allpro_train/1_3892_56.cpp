#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define mp(a,b) make_pair((a),(b))
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x)
#endif

typedef long long int ll;
typedef pair<int,int> pii;
//template<typename T> using vec=std::vector<T>;

const int INF=1<<30;
const long long int INF_=1LL<<58;
const double EPS=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
	os << "[";
	for (const auto &v : vec) {
		os << v << ",";
	}
	os << "]";
	return os;
}

pii grid[100][100];
bool done[100][100];
int num[100][100];
int cnt;

int DFS(int x,int y){
	if(done[x][y]){
		if(num[x][y]==0) return ++cnt;
		return num[x][y];
	}

	done[x][y]=true;
	return num[x][y]=DFS(grid[x][y].first,grid[x][y].second);
}

void Solve(){
	int n;
	while(true){
		cnt=0;
		fill_n((bool*)done,100*100,false);
		fill_n((int*)num,100*100,0);
		cin >> n;
		if(n==0) break;

		
		rep(i,0,n) rep(j,0,n){
			int x,y;
			cin >> x >> y;
			grid[j][i]=mp(x,y);
		}

		rep(i,0,n){
			rep(j,0,n){
				if(!done[i][j]) DFS(i,j);
			}
		}
		cout << cnt << endl;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	Solve();
	return 0;
}