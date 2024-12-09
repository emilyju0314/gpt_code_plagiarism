#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n, K, D[501000], S[501000];
char p[501000], q[501000];
struct STK {
	int num, T;
};
deque<STK> Deq[2];
void Ins(int a) {
	int T = D[a] - S[a + 1] / 2 + 1;
	int pv = S[a + 1] % 2;
	while (!Deq[pv].empty() && Deq[pv].back().T >= T)Deq[pv].pop_back();
	Deq[pv].push_back({ a,T });
}
int main() {
	int i;
	scanf("%d%d", &n, &K);
	scanf("%s", p + 1);
	scanf("%s", q + 1);
	for (i = 2; i <= n; i++) {
		S[i] = S[i - 1];
		if (q[i] != q[i - 1])S[i]++;
	}
	Ins(0);
	for (i = 1; i <= n; i++) {
		int pv = S[i] % 2;
		if (p[i] == q[i])D[i] = D[i - 1];
		else D[i] = D[i - 1] + 1;
		while (!Deq[pv].empty() && Deq[pv].front().num + K < i)Deq[pv].pop_front();
		if (!Deq[pv].empty())D[i] = min(D[i], S[i]/2 + Deq[pv].front().T);
		Ins(i);
	}
	printf("%d\n", D[n]);
}