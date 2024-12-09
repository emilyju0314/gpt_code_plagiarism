#include<iostream>
using namespace std;

int n;

int solve(){
	int ans = 0;
	while(n != 1){
		ans++;
		if(n%2){
			n *= 3;
			n++;
		}else
			n/=2;
	}
	return ans;
}

int main(){
	while(true){
		cin >> n;
		if(!n)
			return 0;
		cout << solve() << endl;
	}
}