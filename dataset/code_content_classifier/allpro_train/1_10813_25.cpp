#include <iostream>
#include <algorithm>
#include <utility>
#include <array>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define ALL(c) c.begin(),c.end()
#define RALL(c) c.rbegin(),c.rend()
#define SORT(x) sort((x).begin(),(x).end())
#define REP(i,x,y) for(int i=(x);i<(y);++i)
#define MP(a,b) make_pair((a),(b))
#define F_ first
#define S_ second
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x)
#endif
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
	os << "[";
	for(const auto &v : vec){
		os << v << ",";
	}
	os << "]";
	return os;
}

typedef long long int lli;
typedef pair<short,short> P;

const int INF=1<<30;
const long long int INF_=1LL<<58;
const double EPS=1e-9;
const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

struct Rect{
	short x1,x2,y1,y2;
};

class Compare{
	public:
	bool operator()(const Rect &rect1,const Rect &rect2){
		return rect1.y1<rect2.y1;
	}
};

inline short max(short a,short b){
	if(a>b) return a;
	else return b;
}
	
int CalcSize(vector<Rect> &rects){
	int result=0;
	REP(x,0,10010){
		int y=0;
		REP(i,0,rects.size()){
			if(rects[i].x1<=x&&x<rects[i].x2){
				if(rects[i].y2>y) result+=rects[i].y2-max(y,rects[i].y1);
				y=max(y,rects[i].y2);
			}
		}
	}
	return result;
}

int Count(vector<Rect> &rects,vector<vector<bool> > &flag,int x){
	int result=0,y=0;
	REP(i,0,rects.size()){
		if(rects[i].x1<=x&&x<rects[i].x2){
			for(y=max(y,rects[i].y1); y<rects[i].y2; ++y){
				if(!flag[(x-1)%3][y]) ++result;
				if(!flag[(x+1)%3][y]) ++result;
				if(!flag[x%3][y-1]) ++result;
				if(!flag[x%3][y+1]) ++result;
			}
		}
	}
	return result;
}

int CalcLength(vector<Rect> &rects){
	int result=0,index=0;
	vector<vector<bool> > flag(3,vector<bool>(10010));
	REP(x,1,10009){
		if(x-2>=0) fill(flag[(x-2)%3].begin(),flag[(x-2)%3].end(),false);
		int y=0;
		REP(i,0,rects.size()){
			if(rects[i].x1<=x+1&&x+1<rects[i].x2){
				if(rects[i].y2>y) fill_n(flag[(x+1)%3].begin()+max(y,rects[i].y1),rects[i].y2-max(y,rects[i].y1),true);
				y=max(rects[i].y2,y);
			}
		}
		result+=Count(rects,flag,x);
	}
	return result;
}

int main(){
	int N,R;
	while(cin >> N >> R&&!(N==0&&R==0)){
		vector<Rect> rects(N);
		REP(i,0,N){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			rects[i].x1=x1+4;
			rects[i].y1=y1+4;
			rects[i].x2=x2+4;
			rects[i].y2=y2+4;
		}
		sort(rects.begin(),rects.end(),Compare());
		cout << CalcSize(rects) << endl;
		if(R==2) cout << CalcLength(rects) << endl;
	}
	return 0;
}