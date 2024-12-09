#include <iostream>
using namespace std;

int main(){
	int n,i,a[10],b,j;
	while(cin >> n && n){
		for(i=0;i<10;i++){
			a[i] = 0;
		}
		for(i=0;i<n;i++){
			cin >> b;
			a[b]++;
		}
		for(i=0;i<10;i++){
			if(a[i] == 0) cout << "-" << endl;
			else{
				for(j=0;j<a[i];j++){
					cout << "*";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}