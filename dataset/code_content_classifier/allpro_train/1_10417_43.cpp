// What a dp on flow!

#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second

const int maxn = 7;
const int maxt = 16000;
const int maxa = 6;

int n, m, tot;
int a[maxn], b[maxn], c[maxn][maxn];
int f[maxn][maxt], g[maxn][maxa][maxt];
int h[maxt][maxn];

inline int ID(int *tmp){
	int ret = 0; FOR(i, 0, m) (ret *= (b[i] + 1)) += tmp[i];
	return ret;
}

inline void unID(int ret, int *tmp){
	for(int i = m - 1; i >= 0; ret /= (b[i--] + 1))
		tmp[i] = ret % (b[i] + 1);
	return;
}

inline void trans( int i, int S){
	memset(g, 0x3f, sizeof(g));
	g[0][0][S] = 0;
	
	FOR(it, 0, m) REP(j, 0, a[i]) FOR(T, 0, tot) if(g[it][j][T] != 0x3f3f3f3f){
		REP(k, 0, min(a[i] - j, h[T][it])){
			h[T][it] -= k;
			//printf("it = %d j = %d T = %d k = %d nT = %d %d\n", it, j, T, k, ID(h[T]), g[it][j][T] + c[i][it] * (k != 0));
			g[it + 1][j + k][ID(h[T])] = min(g[it + 1][j + k][ID(h[T])], g[it][j][T] + c[i][it] * (k != 0));
			h[T][it] += k;
		}
	}
	
	FOR(T, 0, tot) if(g[m][a[i]][T] != 0x3f3f3f3f){
		//printf("T = %d g = %d\n", T, g[m][a[i]][T]);
		f[i + 1][T] = min(f[i + 1][T], g[m][a[i]][T] + f[i][S]);
	}
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	
	FOR(i, 0, n)
		scanf("%d", a + i);
	FOR(i, 0, m)
		scanf("%d", b + i);
	FOR(i, 0, n) FOR(j, 0, m)
		scanf("%d", &c[i][j]);
		
	tot = 1; FOR(i, 0, m) (tot *= b[i] + 1);
	
	FOR(S, 0, tot){
		unID(S, h[S]);
	}

	memset(f, 0x3f, sizeof(f));
	f[0][ID(b)] = 0;
	
	FOR(i, 0, n) FOR(S, 0, tot) if(f[i][S] != 0x3f3f3f3f){
		//printf("i = %d S = %d f = %d\n", i, S, f[i][S]);
		trans(i, S);
	}
		
	int ans = 0x3f3f3f3f;
	FOR(S, 0, tot)
		ans = min(ans, f[n][S]);
	printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
	return 0;
}
