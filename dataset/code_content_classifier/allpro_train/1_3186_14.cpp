#pragma region include
#include <iostream>
#include <iomanip>
#include <stdio.h>

#include <sstream>
#include <algorithm>
#include <cmath>
#include <complex>

#include <string>
#include <cstring>
#include <vector>
#include <tuple>
#include <bitset>

#include <queue>
#include <complex>
#include <set>
#include <map>
#include <stack>
#include <list>

#include <fstream>
#include <random>
//#include <time.h>
#include <ctime>
#pragma endregion //#include
/////////
#define REP(i, x, n) for(int i = x; i < n; ++i)
#define rep(i,n) REP(i,0,n)
#define ALL(X) X.begin(), X.end()
/////////
#pragma region typedef
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef std::pair<LL,LL> PLL;//
typedef std::pair<int,int> PII;//
#pragma endregion //typedef
////定数
const int INF = (int)1e9;
const LL MOD = (LL)1e9+7;
const LL LINF = (LL)1e18+20;
const double PI = acos(-1.0);
const double EPS = 1e-9;
/////////
using namespace::std;

bool END = false;
int ENDcount = 0;
vector< vector< vector<int> > > word(7);

bool check(deque<int> v){
	++ENDcount;
	if( ENDcount > 420 ){
		END = true;
		return true;
	}
	int size = v.size();
	string A,B;
	for(int i=0;i<size;++i){
		if( v[i]&1 ){
			A += '#';
		}else{
			A += '.';
		}
		if( v[i]&2 ){
			B += '#';
		}else{
			B += '.';
		}
	}
	cout << A << '\n' << B << endl;
	string res;
	cin >> res;
	if( res[0] == 'T' ){
		return true;
	}else if( res[0] == 'F' ){
		return false;
	}
	END = true;
	return true;
}

void solve(){
	int N;
	cin >> N;
	
	deque<int> ans;
	int pos = -1;
	while(1){//右に伸ばす
		ans.push_back(0);
		++pos;
		bool flag = false;
		for(int i=0;i<4;++i){
			ans[pos] = i;
			if( check( ans ) ){
				flag = true;
				if( END ){
					return;
				}
				break;
			}
		}
		if( flag == false ){//右に伸ばす4通りがダメだった
			ans.pop_back();//右の伸ばしたものを消す。
			break;
		}
	}

	while(1){//左に伸ばす
		ans.push_front(0);
		for(int i=0;i<4;++i){
			ans[0] = i;
			if( check( ans ) ){
				if( END ){
					return;
				}
				break;
			}
		}
	}
}

#pragma region main
signed main(void){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cout << std::fixed;//小数を10進数表示
	cout << setprecision(16);//小数点以下の桁数を指定//coutとcerrで別	

	solve();
}
#pragma endregion //main()