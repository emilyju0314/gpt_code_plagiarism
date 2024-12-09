#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<map>
#include<random>
#include<functional>
#include<utility>

typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define P pair<int, int>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define VI vector<int>
#define VII vector<VI>

using namespace std;



int N;
P A[100005], B[100005];
int p[100005];
int main() {
	cin >> N;
	rep(i, N) {
		cin >> A[i].first;
		A[i].second = i;
	}
	rep(i, N) {
		cin >> B[i].first;
		B[i].second = i;
	}
	sort(A, A + N);
	sort(B, B + N);

	rep(i, N) {
		if (A[i].first > B[i].first) {
			cout << "No" << endl;
			return 0;
		}
	}

	rep(i, N - 1) {
		if (B[i].first >= A[i + 1].first) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	rep(i, N) {
		p[A[i].second] = B[i].second;
	}
	int cnt = 0;
	int x = 0;
	do
	{
		x = p[x];
		cnt++;
	} while (x != 0);
	if (cnt != N) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;

	return 0;
}
