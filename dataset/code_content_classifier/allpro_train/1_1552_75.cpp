#include <iostream>

using namespace std;

#define REP(i,n) for (int i=0; i<n; i++)

int main(){
	int n, d[1003];
	bool appears[1003];
	
	REP(i,1000){
		appears[i] = false;
	}
	
	cin >> n;
	REP(i,n){
		cin >> d[i];
	}
	
	int d1, d2, d3;
	
	REP(i,n){
		d1 = d[i];
		appears[d1] = true;
		if (i+1<n){
			d2 = d[i+1];
			appears[d1*10+d2] = true;
		}
		if (i+2<n){
			d3 = d[i+2];
			appears[d1*100+d2*10+d3] = true;
		}
	}
	
	for (int i=0; i<1000; i++){
		if (!appears[i]){
			cout << i << endl; 
			break;
		}
	}
	
	return 0;
	
}
