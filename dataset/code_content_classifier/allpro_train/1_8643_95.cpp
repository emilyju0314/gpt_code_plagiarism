#include<iostream>
#include<map>
using namespace std;

int n, k;
bool m[10];

int main(){

ios::sync_with_stdio(0);
cin.tie(0), cout.tie(0);

cin >> n >> k;

for(int i=1,x;i<=k;i++){
cin >> x;
m[x] = 1;
}

for(int i=n;;i++){
	int v = i;
	bool ok = 1;

	while (v != 0) {
		int last = v % 10;

		if (m[last]) {
			ok = 0;
		}		
		
		v /= 10;
	}

	if (ok) {
		cout << i;
		break;
	}
}

return 0;
}