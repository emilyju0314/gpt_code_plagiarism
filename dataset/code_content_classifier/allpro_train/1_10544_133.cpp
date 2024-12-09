#include <iostream>
using namespace std;

string a;
int cnt;
int main() {
	cin>> a;
	for(auto x:a) if(x=='x') cnt++;
	cout<< (cnt<=7 ? "YES" : "NO");
	return 0;
}