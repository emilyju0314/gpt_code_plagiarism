#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<string, int> ps;

int main()
{
	queue<ps> Q;

	int n, q, st = 0;
	cin >> n >> q;

	ps p;
	while (n--) {
		cin >> p.first >> p.second;
		Q.push(p);
	}

	while (!Q.empty()) {
		ps t = Q.front();
		Q.pop();
		if (t.second <= q) {
			st += t.second;
			cout << t.first << " " << st << endl;
		} else {
			st += q;
			t.second -= q;
			Q.push(t);
		}
	}
}
