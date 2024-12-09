#include<iostream>
#include<set>
using namespace std;

int main() {
	int a[4], b[4];
	while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
		int hit = 0, blow = 0;
		set<int> S;
		for (int i = 0; i < 4; i++) {
			S.insert(a[i]);
		}
		for (int i = 0; i < 4; i++) {
			cin >> b[i];
			if (b[i] == a[i]) hit++;
			if (S.find(b[i]) != S.end()) {
				blow++;
			}
		}
		cout << hit << " " << blow - hit << endl;
	}
}
