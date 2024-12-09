#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		int a,b;
		cin >> a >> b;
		if(a==0 && b==0) break;
		
		int rem = b-a;
		int ans[3] = {};
		ans[2] = rem/1000;
		rem %= 1000;
		ans[1] = rem/500;
		rem %= 500;
		ans[0] = rem/100;
		cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	}
	return 0;
}
