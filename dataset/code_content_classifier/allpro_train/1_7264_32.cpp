#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

struct init{
	init(){
		cin.tie(0); ios::sync_with_stdio(false);
	}
}________init;
int main() {

#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
#endif
	int W, H,N;
	while (cin >> W >> H >> N){
		int  res = 0;
		int a = 1, b = 1;
		while (N--){
			int p;
			cin >> p;
			if (p == 0)a++;
			else b++;
			if (a == W || a == W + H - 1)continue;
			if (a < W){
				res += (a == b);
			}
			else if (a < W + H - 1){
				res += (a == b + 2);
			}
			else res += (a == b +4);
		}
		cout << res << endl;
	}
	return 0;
}