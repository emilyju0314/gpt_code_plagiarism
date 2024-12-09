#include <iostream>
using namespace std;
int p, q, x, y;
string s;
int main() {
	cin>>p>>q>>x>>y;
	x-=p, y-=q, p=q=0;
	while(q++<y) s+='U';
	while(p++<x) s+='R';
	while(--q) s+='D';
	while(--p) s+='L';
	s+="LU";
	while(q++<y) s+='U';
	while(p++<x) s+='R';
	s+="RDRD";
	while(--q) s+='D';
	while(--p) s+='L';
	s+="LU";
	cout<<s;
	return 0;
}