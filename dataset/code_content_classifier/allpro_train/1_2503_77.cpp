#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
int main (){

	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;
		string c;
		cin >> c;
		int maisu[10];
		for (int i = 0; i < N; i++){
			maisu[i] = 0;
		}
		int ba = 0;
		int turn = 0;
		for (int i = 0; i < c.size(); i++){
			if(c[i] == 'M') {
			   maisu[turn]++;
			}
			else if(c[i] == 'S') {
				maisu[turn]++;
				ba += maisu[turn];
				maisu[turn] =0;
			}
			else {
				maisu[turn]++;
				maisu[turn] += ba;
				ba = 0;
			}
			
			turn++;
			turn %= N;
		}
		sort(maisu,maisu+N);
		for (int i = 0; i < N; i++){
			cout << maisu[i] << " ";
		}
		cout << ba << endl;
	}
return 0;
}