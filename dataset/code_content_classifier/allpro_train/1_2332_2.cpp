#include <bits/stdc++.h>
#include <sys/timeb.h>
using namespace std;
typedef long long LL;
struct P { int x, y; };
double len(P a) { return sqrt(1.0 * a.x * a.x + 1.0 * a.y * a.y); }
P operator + (P a, P b) { return {a.x + b.x, a.y + b.y}; }
P operator - (P a, P b) { return {a.x - b.x, a.y - b.y}; }
bool operator < (P a, P b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
bool operator == (P a, P b) { return a.x == b.x & a.y == b.y; }
double len(const vector<P> &a) {
	double res = 0;
	for (int i = 0; i < (int) a.size() - 1; ++ i) {
		res += len(a[i + 1] - a[i]);
	}
	return res;
}
LL det(P a, P b) { return 1LL * a.x * b.y - 1LL * a.y * b.x; }
int sign(LL x) { return (x > 0) - (x < 0); }
typedef vector<vector<P>> Convex;
#define sz(x) ((int) x.size())
int lb(P x, const vector<P> & v, int le, int ri, int sg) {
	if (le > ri) le = ri;
	int s(le), t(ri);
	while (le != ri) {
		int mid((le + ri) / 2);
		if (sign(det(v[mid] - x, v[mid + 1] - v[mid])) == sg)
			le = mid + 1; else ri = mid;
	}
	return le; // le 即为下标, 按需返回
}
// v[0] 为顺时针上凸壳, v[1] 为顺时针下凸壳, 均允许起始两个点横坐标相同
// 返回值为真代表严格在凸包外, 顺时针旋转在 d1 方向先碰到凸包
bool getTan(P x, const Convex & v, int & d1, int & d2) {
	if (x.x < v[0][0].x) {
		d1 = lb(x, v[0], 0, sz(v[0]) - 1, 1);
		d2 = lb(x, v[1], 0, sz(v[1]) - 1, -1) + (int) v[0].size() - 1;
		return true;
	} else if(x.x > v[0].back().x) {
		d1 = lb(x, v[1], 0, sz(v[1]) - 1, 1) + (int) v[0].size() - 1;
		d2 = lb(x, v[0], 0, sz(v[0]) - 1, -1);
		return true;
	} else {
		for(int d(0); d < 2; d++) {
			int id(lower_bound(v[d].begin(), v[d].end(), x,
						[&](const P & a, const P & b) {
						return d == 0 ? a < b : b < a;
						}) - v[d].begin());
			if (id && (id == sz(v[d]) || det(v[d][id - 1] - x, v[d][id] - x) > 0)) {
				d1 = lb(x, v[d], id, sz(v[d]) - 1, 1);
				d2 = lb(x, v[d], 0, id, -1);
				if (d) {
					d1 += (int) v[0].size() - 1;
					d2 += (int) v[0].size() - 1;
				}
				return true;
			}
		}
	}
	return false;
}
const int N = 1e5 + 5;
Convex build(vector<P> &a) {
	Convex res (2);
	sort(a.begin(), a.end());
	static int pop_count[N];
	int n = (int) a.size();
	vector<P> b;
	for (int i = 0; i < n; ++ i) {
		while (res[0].size() > 1 && det(a[i] - res[0][(int) res[0].size() - 2], res[0].back() - res[0][(int) res[0].size() - 2]) <= 0) {
			b.push_back(res[0].back());
			res[0].pop_back();
		}
		res[0].push_back(a[i]);
	}
	for (int i = n - 1; i >= 0; -- i) {
		while (res[1].size() > 1 && det(a[i] - res[1][(int) res[1].size() - 2], res[1].back() - res[1][(int) res[1].size() - 2]) <= 0) {
			b.push_back(res[1].back());
			res[1].pop_back();
		}
		res[1].push_back(a[i]);
	}
	sort(b.begin(), b.end());
	//printf("b = "); for (P x : b) printf("%d %d & ", x.x, x.y); puts("");
	vector<P> c;
	for (int i = 0; i + 1 < (int) b.size(); ++ i) {
		if (b[i] == b[i + 1]) c.push_back(b[i]);
	}
	swap(a, c);
	return res;
}
int size_Convex(const Convex &a) {
	if (a[0].empty()) return 0;
	int n = (int) a[0].size() + (int) a[1].size() - 2;
	return max(n, 1);
}
P get_Convex(const Convex &a, int i) {
	if (i < a[0].size()) return a[0][i];
	return a[1][i - (int) a[0].size() + 1];
}
int touch1, touch2;
vector<P> insert(P L, P R, const Convex & a) {
	touch1 = touch2 = -1;
	if (L == R || a[0].empty()) return {L, R};
	int d1, d2;
	//printf("L : %d %d  R : %d %d   cut : ", L.x, L.y, R.x, R.y);
	//for (int i = 0; i < size_Convex(a); ++ i) printf("%d %d & ", get_Convex(a, i).x, get_Convex(a, i).y); puts("");
	assert(getTan(L, a, d1, d2));
	if (det(get_Convex(a, d1) - L, R - L) >= 0) return {L, R};
	touch2 = touch1 = d1;
	int n = size_Convex(a);
	vector<P> res = {L, get_Convex(a, d1)};
	P las = res.back();
	for (int i = (d1 + 1) % n; det(get_Convex(a, i) - las, R - las) < 0; i = (i + 1) % n) {
		res.push_back(get_Convex(a, i));
		touch2 = i;
		las = res.back();
	}
	res.push_back(R);
	return res;
}
int main() {
	int n;
	scanf("%d", &n);
	//n = 10;
	// 10 4148335439 5001
	// 8 4148842258 501
	//struct timeb timeSeed;
	//ftime(&timeSeed);
	//unsigned int seed = timeSeed.time * 1000 + timeSeed.millitm;
	//int seed = time(0);
	//cout << seed << endl;
	//srand(seed);
	vector<P> all;
	for (int i = 0; i < n; ++ i) {
		int x, y;
		scanf("%d%d", &x, &y);
		//x = rand() % 50001;
		//y = rand() % 50001;
		//printf("%d %d\n", x, y);
		all.push_back({x, y});
	}
	sort(all.begin(), all.end()); all.erase(unique(all.begin(), all.end()), all.end());
	auto all2 = all;
	Convex A = build(all); int nA = size_Convex(A);
	//for (int i = 0; i < nA; ++ i) printf("%d %d & ", get_Convex(A, i).x, get_Convex(A, i).y); puts("");
	Convex B = build(all); int nB = size_Convex(B);
	//for (int i = 0; i < nB; ++ i) printf("%d %d & ", get_Convex(B, i).x, get_Convex(B, i).y); puts("");
	Convex C = build(all); int nC = size_Convex(C);
	//for (int i = 0; i < nC; ++ i) printf("%d %d & ", get_Convex(C, i).x, get_Convex(C, i).y); puts("");
	//printf("%d %d %d =======\n", nA, nB, nC);
	/*double DP = 0;
	for (int i = 0; i < all2.size(); ++ i) {
		for (int k = i; k < all2.size(); ++ k) {
		vector<P> bll;
		for (int j = 0; j < all2.size(); ++ j) if (i != j && k != j) bll.push_back(all2[j]);
		Convex con = build(bll);
		double tmp = len(A[0]) + len(A[1]) - len(con[0]) - len(con[1]);
		//if (tmp > DP) printf("DP %d %d  %d %d  %.10f\n", all2[i].x, all2[i].y, all2[k].x, all2[k].y, tmp);
		DP = max(DP, tmp);
		}
	}*/
	vector<pair<double, int>> val;
	double ans = 0;
	for (int i = 0; i < nA; ++ i) {
		P a = get_Convex(A, i), b = get_Convex(A, (i + 1) % nA), c = get_Convex(A, (i + 2) % nA);
		double res = len(a - b) + len(b - c);
		auto half = insert(a, c, B);
		res -= len(half);
		ans = max(ans, res);
		val.push_back({res, i});
		//printf("b = %d %d  res = %.10f\n", b.x, b.y, res);
		//for (P x : half) printf("%d %d & ", x.x, x.y); puts("");
	}
	sort(val.rbegin(), val.rend());
	for (int i = 0; i < nA; ++ i) {
		double res = val[i].first;
		set<int> adj = {val[i].second, (val[i].second + 1) % nA, (val[i].second - 1 + nA) % nA};
		for (int j = 0; j < nA; ++ j) {
			if (adj.count(val[j].second)) continue;
			ans = max(ans, res + val[j].first);
			break;
		}
	}
	if (nA >= 4) {
		for (int i = 0; i < nA; ++ i) {
			P a = get_Convex(A, i), b = get_Convex(A, (i + 1) % nA), c = get_Convex(A, (i + 2) % nA), d = get_Convex(A, (i + 3) % nA);
			double res = len(a - b) + len(b - c) + len(c - d);
			auto half = insert(a, d, B);
			//for (P x : half) printf("%d %d & ", x.x, x.y); puts("");
			res -= len(half);
			ans = max(ans, res);
			//printf("%d %d %d %d : %.10f\n", b.x, b.y, c.x, c.y, res);
		}
	}
	else {
		assert(nA == 3);
		for (int i = 0; i < nA; ++ i) {
			vector<P> tmp = B[0];
			for (P x : B[1]) tmp.push_back(x);
			tmp.push_back(get_Convex(A, i));
			Convex res = build(tmp);
			ans = max(ans, len(A[0]) + len(A[1]) - len(res[0]) - len(res[1]));
		}
	}
	for (int i = 0; i < nA; ++ i) {
		P a = get_Convex(A, i), b = get_Convex(A, (i + 1) % nA), c = get_Convex(A, (i + 2) % nA);
		double res = len(a - b) + len(b - c);
		auto half = insert(a, c, B);
		int touch1 = ::touch1;
		int touch2 = ::touch2;
		P X = b;
		//printf("touch %d %d\n", touch1, touch2);
		//printf("half : "); for (P x : half) printf("%d %d & ", x.x, x.y); puts("");
		res -= len(half);
		for (int j = 1; j < (int) half.size() - 1; ++ j) {
			P a = half[j - 1], b = half[j], c = half[j + 1];
			assert(touch1 != -1 && touch2 != -1);
			if (nB > 1) {
				if (j == 1) a = get_Convex(B, (touch1 + nB - 1) % nB);
				if (j == (int) half.size() - 2) c = get_Convex(B, (touch2 + 1) % nB);
			}
			double res2 = len(half[j - 1] - b) + len(b - half[j + 1]);
			auto half2 = insert(a, c, C);
			//printf("half2 : "); for (P x : half2) printf("%d %d & ", x.x, x.y); puts("");
			int l = 0, r = (int) half2.size() - 1;
			a = half[j - 1], c = half[j + 1];
			while (l < r && det(half2[l] - a, half2[l + 1] - a) >= 0) l ++;
			while (r > l && det(half2[r] - c, half2[r - 1] - c) <= 0) r --;
			//printf("%d %d\n", l, r);
			vector<P> half3 = {a};
			for (int k = l; k <= r; ++ k) half3.push_back(half2[k]);
			if (l == r && det(c - a, half3.back() - a) <= 0) half3.pop_back();
			half3.push_back(c);
			//printf("half3 : "); for (P x : half3) printf("%d %d & ", x.x, x.y); puts("");
			res2 -= len(half3);
			//printf("%d %d   %d %d  %.5f\n", X.x, X.y, b.x, b.y, res + res2);
			ans = max(ans, res + res2);
		}
	}
	printf("%.10f\n", ans);
	//printf("%.10f\n", DP);
	//if (fabs(ans - DP) > 1e-4) while (1);
}

