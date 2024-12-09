#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	long long a=0, c=0, h=0, m=0, r=0, ans=0;
	cin >> n;
	string s;
	for(int i=0; i<n; i++){
		cin >> s;
		if(s[0]=='A') a++;
		else if(s[0]=='C') c++;
		else if(s[0]=='H') h++;
		else if(s[0]=='M') m++;
		else if(s[0]=='R') r++;
	}
	ans += a*(c*h+c*m+c*r+h*m+h*r+m*r) + c*(h*m+h*r+m*r) + h*m*r;
	cout << ans << endl;
}
