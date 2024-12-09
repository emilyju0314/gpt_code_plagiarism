#include <iostream>

using namespace std;

int main(void){
	while(1){
		int n, m; cin >> n >> m;
		if(!n && !m) break;
		pair<int, int> p[101];
		for(int i=0; i<n; i++){
			cin >> p[i].first >> p[i].second;
		}
		int sum = 0;
		int top[101]={0};

		for(int i=0; i<n; i++){
			if(top[p[i].first] < p[i].second){
				sum += p[i].second;
				sum -= top[p[i].first];
				top[p[i].first] = p[i].second;
			}
		}
	
		cout << sum << endl;
	}
}
