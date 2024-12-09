#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
int d[6][4]={{2,3,5,4}, {1,4,6,3}, {1,2,6,5}, {1,5,6,2}, {1,3,6,4}, {2,4,5,3}};

struct dice{ int t,r; }; //topの数字、回転数
dice cube[3][3][3];
int t[3][3],f[3][3];
bool ans[55];

void solve(int x, int y, int z){
	if(z==3){
		int sum=0;
		REP(i,3) REP(j,3){
			sum += d[cube[2][i][j].t][(cube[2][i][j].r+1)%4];
		}
		ans[sum] = true;
		return;
	}
	
	int nx=x, ny=y, nz=z;
	if(x<2) nx++;
	else{
		nx = 0;
		if(y<2) ny++;
		else{ ny = 0; nz++; }
	}
	
	REP(top,6) REP(rot,4){
		//上面・前面不一致
		if(z==0 && t[y][x]!=0 && (top+1)!=t[y][x]) continue;
		if(y==2 && f[z][x]!=0 && d[top][rot]!=f[z][x]) continue;
		//隣接面不一致
		if(x!=0 && d[cube[x-1][y][z].t][(cube[x-1][y][z].r+1)%4]!=d[top][(rot+1)%4]) continue;
		if(y!=0 && d[cube[x][y-1][z].t][(cube[x][y-1][z].r)]!=d[top][rot]) continue;
		if(z!=0 && cube[x][y][z-1].t != top) continue;
		cube[x][y][z].t = top;
		cube[x][y][z].r = rot;
		solve(nx, ny, nz);
	}
}


int main(){
	int rep;
	cin >> rep;
	for(int r=0; r<rep; r++){
		memset(ans, 0, sizeof(ans));
		REP(i,3) REP(j,3) cin >> t[i][j];
		REP(i,3) REP(j,3) cin >> f[i][j];
		solve(0, 0, 0);
		bool nosol = true;
		REP(i,55){
			if(ans[i]) nosol = false;
		}
		if(nosol){
			cout << 0 << endl;
		}else{
			vector<int> a;
			REP(i,55){
				if(ans[i]) a.push_back(i);
			}
			REP(i, (int)a.size()-1) cout << a[i] << " ";
			cout << a[a.size()-1] << endl;
		}
	}
	return 0;
}
