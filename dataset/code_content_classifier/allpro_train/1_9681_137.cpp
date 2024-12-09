#include <iostream>
using namespace std;
int main(){
	int n; cin >> n;
	int h[n];
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 1; i < n; i++){
		if(h[i-1] < h[i]) h[i]--;
	}
	for(int i = 1; i < n; i++){
		if(h[i-1] > h[i]){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
