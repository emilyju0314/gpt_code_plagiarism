#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int n, r[20005];

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		r[x] = i;
	}
	for(int i=1; i<=n; i++){
		printf("%d ", 30000 * i);
	}
	puts("");
	for(int i=1; i<=n; i++){
		printf("%d ", 30000 * (n + 1 - i) + r[i]);
	}
puts("");
}
