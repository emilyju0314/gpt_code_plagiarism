#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int comp(const void *_c1, const void *_c2){
	int *c1 = (int*)_c1;
	int *c2 = (int*)_c2;
	for(int i = 0; i < 8; i++){
		if(c1[i] != c2[i]) return c1[i]-c2[i];
	}
	return 0;
}

int main(){
	int p[8];
	while(cin >> p[0]){
		for(int i = 1; i < 8; i++){
			cin >> p[i];
		}
		int c[8][8] = {{1,2,1,2,1,4,1,4}};
		for(int i = 1; i < 8; i++){
			for(int j = 0; j < 7; j++){
				c[i][j] = c[i-1][j+1];
			}
			c[i][7] = c[i-1][0];
		}
		qsort(c,8, sizeof c[0], comp);
		int s = 0;
		int d = 0;
		for(int i = 0; i < 8; i++){
			int _s = 0;
			for(int j = 0; j < 8; j++){
				_s += min(p[j],c[i][j]);
			}
			if(_s > s){
				d = i;
				s = _s;
			}
		}
		for(int i = 0; i < 7; i++) cout << c[d][i] << " ";
		cout << c[d][7] << endl;
	}
}