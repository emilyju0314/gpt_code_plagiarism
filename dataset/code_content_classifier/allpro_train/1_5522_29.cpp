#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;cin >> n;
  	int ans = 0;
  	if (n==10||n==100||n==1000||n==10000||n==100000) ans = 10;
  	else while(n) {
    	ans += n%10;
      	n/=10;
    }
  	cout << ans << endl;
}