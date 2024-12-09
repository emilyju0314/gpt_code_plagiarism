#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
	int weight;
	while(cin >> weight){
		if(weight == 0) break;
		int minimum_cost = 100000000;
		for(int i = 0; (i-1) * 200 < weight; i++){
			int w2 = weight - 200 * i;
			for(int j = 0; (j-1) * 300 < w2; j++){
				int w3 = w2 - 300 * j;
				int k = 0;
				while(k * 500 < w3) k++;
				int cost = (i / 5) * 1520 + (i % 5) * 380
					+ (j / 4) * 1870 + (j % 4) * 550
					+ (k / 3) * 2244 + (k % 3) * 850;
				if(i * 200 + j * 300 + k * 500 == weight)
					minimum_cost = min(minimum_cost, cost);
			}
		}
		cout << minimum_cost << endl;
	}
	return 0;
}