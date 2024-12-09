#include <iostream>
#include <cstring>

using namespace std;

int m[50][50];

int main(void){

	int W,H,T;
	int P;

	int x,y,t;
	int b;

	int ans = 0;

	cin >> W >> H >> T;
	cin >> P;

	memset(m,0,sizeof(m));

	for(int i=0;i<P;++i){
		cin >> x >> y >> t;
		if(t<=T){
			m[y][x]++;
		}
	}

	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			cin >> b;

			ans += b*m[i][j];
		}
	}

	cout << ans << endl;
}