#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int num[110]={};

int main() {
	int X, N;
	cin >> X >> N;
	for(int i=0; i<N; ++i){
		int p;
		cin >> p;
		++num[p];
	}
	int ans=0;
	for(int i=1; i<=101; ++i){
		if(num[i]==0){
			if(abs(ans-X)>abs(i-X)){
				ans=i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}