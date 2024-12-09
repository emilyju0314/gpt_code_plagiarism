#include<iostream>
#include<cmath>

#define N 100
#define S 1000

using namespace std;

int main(){

  int n, s;
  long long int soi[10][S + 1] = {};
	
	soi[1][0] = 1;
	
	for(int i=1; i<=N; i++){
		for(int j=8; j>0; j--){
			for(int k=0; k<=S; k++){
				if(soi[j][k] != 0){
					soi[j+1][k + i] += soi[j][k];
				}
			}
		}
		soi[1][i] = 1;
	}
	
	while(1){
		cin >> n >> s;
		if(n == 0 && s == 0) break;
		
		cout << soi[n][s] << endl;
		
	}

  return 0;

}