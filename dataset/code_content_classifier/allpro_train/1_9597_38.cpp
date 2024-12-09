/* - - - - - - - - - - - - - - -
	User : 		VanishD
	problem :
	Points : 	
- - - - - - - - - - - - - - - */
# include <bits/stdc++.h>
# define 	ll 		long long
using namespace std;
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
int read(){
	int tmp = 0, fh = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){ if (ch == '-') fh = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9'){ tmp = tmp * 10 + ch - '0'; ch = getchar(); }
	return tmp * fh;
}
const int N = 61;
vector <int> ea[N], eb[N], e[N];
int ua[N], va[N], ub[N], vb[N], deg[N], use[N], cnt, da[N], db[N], tag[N], n, q[N]; 
void dfs(int x, int fa){
	use[x] = true; cnt++;
	for (unsigned eda = 0, edb = 0; eda < ea[x].size() && edb < eb[x].size(); ){
	//	printf("%d %d\n", ea[x][eda], eb[x][edb]);
		if (ea[x][eda] == eb[x][edb] && ea[x][eda] != fa) dfs(ea[x][eda], x);
		if (edb >= eb[x].size() - 1 || (eda < ea[x].size() - 1 && ea[x][eda + 1] <= eb[x][edb + 1]))
			eda++; else edb++; 
	}
}
void foda(int x, int fa){
	da[x] = fa;
	for (unsigned ed = 0; ed < ea[x].size(); ed++)
		if (ea[x][ed] != fa) foda(ea[x][ed], x);
}
void fodb(int x, int fa){
	db[x] = fa;
	for (unsigned ed = 0; ed < eb[x].size(); ed++)
		if (eb[x][ed] != fa) fodb(eb[x][ed], x);
}
int check(int x){
	memset(use, 0, sizeof(use)); memset(tag, 0, sizeof(tag));
	for (int i = 1; i <= n; i++) ea[i].clear(), eb[i].clear(), e[i].clear();
	for (int i = 1; i < n; i++){
		ea[ua[i]].push_back(va[i]);
		ea[va[i]].push_back(ua[i]);
	}
	for (int i = 1; i < n; i++){
		eb[ub[i]].push_back(vb[i]);
		eb[vb[i]].push_back(ub[i]);
	}
	for (int i = 1; i <= n; i++){
		sort(ea[i].begin(), ea[i].end());
		sort(eb[i].begin(), eb[i].end());
	}
	cnt = 0; dfs(x, 0);
	cnt = n - cnt;
	foda(x, 0); fodb(x, 0);
	for (int i = 1; i <= n; i++){
		if (use[i] == true) continue;
		if (use[da[i]] == false) e[i].push_back(da[i]), tag[da[i]]++;
		if (use[db[i]] == false) e[db[i]].push_back(i), tag[i]++;
	}
	int pl = 1, pr = 0, tmp = 0;
	for (int i = 1; i <= n; i++) if (tag[i] == 0) q[++pr] = i; 
	while (pl <= pr){
		int x = q[pl++]; tmp++;
		for (unsigned i = 0; i < e[x].size(); i++){
			tag[e[x][i]]--;
			if (tag[e[x][i]] == 0) q[++pr] = e[x][i];
		}
	}
	if (tmp == n) return cnt;
		else return inf;
}
int main(){
//	freopen("f.in", "r", stdin);
//	freopen("f.out", "w", stdout);
	for (int opt = read(); opt--; ){
		n = read();
		memset(deg, 0, sizeof(deg));
		for (int i = 1; i < n; i++){
			ua[i] = read(), va[i] = read();
			deg[ua[i]]++; deg[va[i]]++;
		}
		for (int i = 1; i < n; i++)
			ub[i] = read(), vb[i] = read();
		int flag = inf;
		for (int i = 1; i <= n; i++)
			flag = min(check(i), flag);
		for (int i = 1; i <= n; i++){
			if (deg[i] != 1) continue;
			for (int j = 1; j <= n; j++){
				if (i == j) continue;
				for (int k = 1; k < n; k++){
					if (ua[k] == i){
						int tmp = va[k];
						va[k] = j;
						flag = min(flag, check(i) + 1);
						va[k] = tmp;
						break;
					}
					if (va[k] == i){
						int tmp = ua[k];
						ua[k] = j;
						flag = min(flag, check(i) + 1);
						ua[k] = tmp;
						break;
					}
				}
			}
		}
		if (flag == inf)
			printf("-1\n");
			else printf("%d\n", flag); 
	} 
	return 0;
}
