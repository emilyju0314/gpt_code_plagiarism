//#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

#define sc scanf
#define Min(x, y) x = min(x, y)
#define Max(x, y) x = max(x, y)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define pir pair <int, int>
#define MK(x, y) make_pair(x, y)
#define MEM(x, b) memset(x, b, sizeof(x))
#define MPY(x, b) memcpy(x, b, sizeof(x))
#define lowbit(x) ((x) & -(x))
#define P2(x) ((x) * (x))

typedef long long ll;
const int Mod = 1e9 + 7;
const int N = 3e5 + 100;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
inline ll dpow(ll a, ll b){ ll r = 1, t = a; while (b){ if (b & 1)r = (r*t) % Mod; b >>= 1; t = (t*t) % Mod; }return r; }
inline ll fpow(ll a, ll b){ ll r = 1, t = a; while (b){ if (b & 1)r = (r*t); b >>= 1; t = (t*t); }return r; }

vector <int> G[N];
int c[N], n, m;
bool vis[N];

void Init() {
	for (int i = 1; i <= n; i++)
		G[i].clear(), c[i] = vis[i] = 0;
}
int BFS(int x) {
	queue <int> q;
	q.push(x), vis[x] = true;

	int cur = 1;   // 访问过的点数
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		bool ok = true;  // 周围是否无染色的点
		for (auto v : G[u]) {
			if (c[v])
				ok = false;
		}
		if (ok)
			c[u] = 1;
		for (auto v : G[u]) {
			if (!vis[v])
				cur++, vis[v] = true, q.push(v);
		}
	}
	return cur;
}

int main()
{
#ifdef OlaMins
	freopen("D:/input.txt", "r", stdin);
	//freopen("D:/output.txt", "w", stdout);
#endif

	int T; cin >> T;
	while (T--) {
		sc("%d %d", &n, &m);
		Init();

		for (int i = 0; i < m; i++) {
			int u, v;
			sc("%d %d", &u, &v);
			G[u].push_back(v), G[v].push_back(u);
		}
		int cur = BFS(1);
		if (cur != n)
			puts("NO");
		else {
			vector <int> ver;
			for (int i = 1; i <= n; i++) {
				if (c[i])
					ver.push_back(i);
			}
			int sz = SZ(ver);
			printf("YES\n%d\n", sz);
			for (int i = 0; i < sz; i++)
				printf("%d%c", ver[i], " \n"[i == sz - 1]);
		}
	}
	return 0; // 改数组大小!!!用pair改宏定义!!!
}