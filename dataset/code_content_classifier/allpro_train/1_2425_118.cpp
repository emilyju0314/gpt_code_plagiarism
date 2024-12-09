#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;
typedef long long ll;
int num;

bool isparindrome(int n){
	int size = 0;
	int m = n;
	while(m){
		m /= 10;
		size++;
	}
	rep(i, 0, size/2){
		if((n/(int)pow((double)10, i))%10 != (n/(int)pow((double)10, size-i-1))%10) return false;
	}
	return true;
}

int main(){
	cin >> num;
	int d1, d2;
	d1 = num;
	d2 = num;
	while(!isparindrome(d1)){
		d1--;
	}
	while(!isparindrome(d2)){
		d2++;
	}
	int ans;
	if(num-d1 <= d2-num) ans = d1;
	else ans = d2;
	cout << ans << endl;
	
}