#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int d[1500] = {}, c[1500] = {}, mini[1500] = {};
	int n, m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> d[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[i];
		mini[i] = 2000000000;
	}
	mini[0] = 0;
	for(int i = 1;i<=m;i++){
		for(int j = i;j>0;j--){
			mini[j] = min(mini[j], mini[j - 1] + d[j] * c[i]);
		}
	}
	cout << mini[n] << endl;
	return 0;

}