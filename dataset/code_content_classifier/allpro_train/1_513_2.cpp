#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class SuffixArray {
	void CEB(vector<int> &v, vector<int> &b) {
		int vs = v.size(), bs = b.size();
		fill(b.begin(), b.end(), 0);
		for (int i = 0; i < vs; i++) b[v[i]]++;
		for (int i = 1; i < bs; i++) b[i] += b[i - 1];
	}
	void ISort(vector<int> &v, vector<int> &SA, int mv, vector<int> &b, vector<int> &isL) {
		int vs = v.size(), bs = b.size();
		fill(b.begin(), b.end(), 0);
		for (int i = 0; i < vs; i++) b[v[i]]++;
		int sum = 0;
		for (int i = 0; i < bs; i++) b[i] += sum, swap(sum, b[i]);
		for (int i = 0; i < vs; i++) {
			if (SA[i] > 0 && isL[SA[i] - 1]) SA[b[v[SA[i] - 1]]++] = SA[i] - 1;
		}
	}
	void IISort(vector<int> &v, vector<int> &SA, int mv, vector<int> &b, vector<int> &isL) {
		CEB(v, b);
		for (int i = v.size() - 1; i >= 0; i--) {
			if (SA[i] > 0 && !isL[SA[i] - 1]) SA[--b[v[SA[i] - 1]]] = SA[i] - 1;
		}
	}
	vector<int>SA_IS(vector<int> v, int mv) {
		int vs = v.size();
		if (vs == 1) return vector<int>(1, 0);
		vector<int> isL(vs), b(mv + 1), SA(vs, -1), ord(vs);
		auto isLMS = [&](int x)->bool { return x > 0 && isL[x - 1] && !isL[x]; };
		for (int i = vs - 2; i >= 0; i--) isL[i] = (v[i] > v[i + 1]) || (v[i] == v[i + 1] && isL[i + 1]);
		CEB(v, b);
		for (int i = 0; i < vs; i++) {
			if (isLMS(i)) SA[--b[v[i]]] = i;
		}
		ISort(v, SA, mv, b, isL);
		IISort(v, SA, mv, b, isL);
		int cur = 0;
		for (int i = 0; i < vs; i++) {
			if (isLMS(i)) ord[i] = cur++;
		}
		vector<int> nxv(cur);
		cur = -1;
		int prev = -1;
		for (int i = 0; i < vs; i++) {
			if (!isLMS(SA[i])) continue;
			bool diff = false;
			for (int d = 0; d < vs; d++) {
				if (prev == -1 || v[SA[i] + d] != v[prev + d] || isL[SA[i] + d] != isL[prev + d]) {
					diff = true;
					break;
				}
				else if (d && isLMS(SA[i] + d))break;
			}
			if (diff) cur++, prev = SA[i];
			nxv[ord[SA[i]]] = cur;
		}
		vector<int> reord(nxv.size());
		for (int i = 0; i < vs; i++) {
			if (isLMS(i)) reord[ord[i]] = i;
		}
		vector<int> nxSA = SA_IS(nxv, cur);
		CEB(v, b);
		for (int i = 0; i < SA.size(); i++) SA[i] = -1;
		for (int i = nxSA.size() - 1; i >= 0; i--) {
			SA[--b[v[reord[nxSA[i]]]]] = reord[nxSA[i]];
		}
		ISort(v, SA, mv, b, isL);
		IISort(v, SA, mv, b, isL);
		return SA;
	}
	vector<int>SA_IS(string s) {
		vector<int> v(s.size() + 1);
		for (int i = 0; i < s.size(); i++) v[i] = s[i] + 1;
		return SA_IS(v, *max_element(v.begin(), v.end()));
	}
public:
	string s;
	vector<int> sa;
	void init(string &T) {
		s = T;
		sa = SA_IS(s);
	}
	SuffixArray(string &t) { init(t); }
	SuffixArray() {}
	bool contain(string &t) {
		int a = 0, b = s.size();
		while (b - a > 1) {
			int c = (a + b) / 2;
			if (s.compare(sa[c], t.size(), t) < 0) a = c;
			else b = c;
		}
		return s.compare(sa[b], t.size(), t) == 0;
	}
};
int q; string s, t;
int main() {
	cin >> s >> q;
	SuffixArray v(s);
	for(int i = 0; i < q; i++) {
		cin >> t;
		cout << (v.contain(t) ? 1 : 0) << endl;
	}
}