/*
This is code of SuperJ6 for Codeforces.
Don't copy my code during f*kin' contests.

2.71828182845904523536
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

const int mxn = 503;
int n, k;
int a[mxn], vis[mxn];

void swp(int x){
	swap(a[x], a[x + 1]), swap(vis[x], vis[x + 1]);
}

void answer(){
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++){
		char c;
		cin >> c;
		a[i] = c - 'a', vis[i] = 0;
	}
	a[0] = -1, a[n + 1] = a[n + 2] = k;
	
	for(int i = 1; i <= n; i++) if(!vis[i]){
		vis[i] = 1;
		if(!vis[i + 1] && a[i + 1] < a[i] && a[i + 1] < a[i - 1]){
			swp(i--);
		}else if(a[i] == k - 1){
			a[i] = 0;
		}else if(a[i] < a[i - 1]){
			swp(i - 1);
		}else if(!vis[i + 1] && ((a[i + 1] && a[i + 2] >= a[i + 1] - 1 && a[i + 1] < a[i]) || (a[i + 1] == k - 1 && a[i] > 1))){
			swp(i--);
		}else if(a[i]){
			a[i]--;
		}
	}
	
	for(int i = 1; i <= n; i++) cout << (char)(a[i] + 'a');
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) answer();

	return 0;
}