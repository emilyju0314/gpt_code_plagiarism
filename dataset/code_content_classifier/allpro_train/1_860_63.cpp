#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)

int main()
{
	int N;
	vector<int> member(100002, 0);
	cin >> N;
	REP(i, 0, N) {
		int a, b;
		cin >> a >> b;
		member[a-1]++;
		member[b]--;
	}
	REP(i, 0, 100001) member[i + 1] += member[i];

	int ans = 0;
	REP(i, 0, 100002) {
		if (member[i] >= i) ans = max(ans, i);
	}

	cout << ans << endl;
	return 0;
}