#include<iostream>
#include<algorithm>
using namespace std;

#define INF 1145141919
#define MAX_N 114514
#define MAX_LOOP 5000

int x[MAX_N], pass[MAX_N], shortest[MAX_N];
int n;

void _set(int p) {
	int loop;
	int cx;
	for (int i = 0; i < p; i++) {
		loop = 0;
		cx = i;
		while (x[cx] != 0) {
			cx += x[cx];
			loop++;
			if (loop >= MAX_LOOP) {
				pass[i] = INF;
				goto E;
			}
		}
		pass[i] = cx;
	E:;
	}
}

int shortestpath(int p) {
	for (int i = 0; i < p; i++) { shortest[i] = INF; }
	shortest[0] = 0;
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < p; j++) {
			if (shortest[j] != INF) {
				for (int k = 1; k <= 6; k++) {
					if (pass[j + k] != INF) {
						shortest[pass[j + k]] = min(shortest[pass[j + k]], shortest[j] + 1);
					}
				}
			}
		}
	}
	return shortest[p - 1];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	_set(n);
	cout << shortestpath(n) << endl;
	return 0;
}