#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second
 
const int mxn = 100000, k = 13;
int n;
int a[mxn];
 
int qry(int x, int y, int z){
	int ret;
	cout << "? " << (x + 1) << " " << (y + 1) << " " << (z + 1) << endl;
	cin >> ret;
	return ret;
}
 
void answer(){
	cin >> n;
	
	int x, y;
	for(x = 0; x < k; x++)
	for(y = 0; y < x; y++)
	for(int i = 0; i < y; i++){
		if(qry(x, y, i) <= (n - 4) / 6) goto hell;
	}
	
	hell:
	int z = 0;
	for(int i = 0; i < n; i++){
		a[i] = i != x && i != y ? qry(x, y, i) : 0;
		if(a[i] > a[z]) z = i;
	} 
	
	int w = 0;
	while(a[w] != a[z] - 1) w++;
	
	for(int i = w + 1; i < n; i++){
		if(a[i] == a[w] && qry(x, z, w) > qry(x, z, i)) w = i;
	} 
	
	a[z] = 0, a[w] = 1;
	for(int i = 0; i < n; i++) if(i != z && i != w) a[i] = qry(w, z, i) + 1;
	
	if(a[0] > a[1]) for(int i = 0; i < n; i++) a[i] = n - a[i] - 1;
	
	cout << "!";
	for(int i = 0; i < n; i++) cout << " " << (a[i] + 1);
	cout << endl;
	
	int ret;
	cin >> ret;
	
	if(!~ret) exit(0);
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) answer();
 
	return 0;
}
