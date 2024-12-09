#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
int main(){
	cin >> a >> b >> c >> d;
	if(d&1)cout << b-a;
	else cout << a-b;
	return 0;
}
