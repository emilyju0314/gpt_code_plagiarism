#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

long long int c[150][150];

int main(){
	
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> c[i][j];
		}
	}
	
	long long int ans = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			ans += min(c[i][j], c[j][i]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}