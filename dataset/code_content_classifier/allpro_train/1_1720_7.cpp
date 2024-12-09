#include <iostream>
#include <cstdio>
#define INF 1e+9
using namespace std;

int h,w,ma = 0,mi = INF;
int field[2000][2000],tmp[2000][2000];
bool used[2000][2000];

bool C(int x){
	int remain = h * w,limit = w;
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++) used[i][j] = false;
	}
	for(int i = 0;i < h;i++){
		for(int j = 0;j < limit;j++){
			if(!used[i][j] && ma - x <= field[i][j]){
				used[i][j] = true;
				remain--;
			}else {
				limit = j;
				break;
			}
		}
	}
	limit = -1;
	for(int i = h - 1;i >= 0;i--){
		for(int j = w - 1;j > limit;j--){
			if(!used[i][j] && mi + x >= field[i][j]){
				used[i][j] = true;
				remain--;
			}else {
				limit = j;
				break;
			}
		}
	}
	return !remain;
}

void rotate(){
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			tmp[j][h - i - 1] = field[i][j];
		}
	}
	int t = h;
	h = w;
	w = t;
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++) field[i][j] = tmp[i][j];
	}
}

int main(){
	int res = INF;
	cin >> h >> w;
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++) {
			scanf("%d",&field[i][j]);
			ma = max(ma,field[i][j]);
			mi = min(mi,field[i][j]);
		}
	}
	for(int i = 0;i < 4;i++){
		int low = -1,up = INF + 1;
		while(up - low > 1){
			int mid = (low + up) / 2;
			if(C(mid)) up = mid;
			else low = mid;
		}
		res = min(res,up);
		rotate();
	}
	cout << res << endl;
	return 0;
}