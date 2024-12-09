#include <iostream>
using namespace std;
int main(){
	int n, p;
	while (cin >> n >> p, n or p){
		int c = p, s[n], M = 1;
		for (int i = 0; i < n; ++i) s[i] = 0;
		while (M){
			for (int i = 0; i < n; ++i){
				if (c){
					c--;
					s[i]++;
					if (s[i] == p){
						cout << i << endl;
						M = 0;
						break;
					}
				}else{
					c += s[i];
					s[i] = 0;
				}
			}
		}
	}
	return 0;
}