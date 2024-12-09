#include <bits/stdc++.h>
using namespace std;
complex<double> P;

struct SAComp{
	const int h;
	const vector<int> &g;
	SAComp(int h,vector<int> &g) : h(h), g(g) {}
	bool operator ()( int a,int b){
		return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a+h] < g[b+h];
	}
};

vector<int> buildSA(string &t){
	const int n = t.size();
	vector<int> g(n+1),b(n+1),v(n+1);
	for(int i = 0 ; i < n + 1 ; i++)
		v[i] = i, g[i] = t[i];
	b[0] = 0;
	b[n] = 0;
	sort(v.begin(),v.end(),SAComp(0,g));
	for(int h = 1 ; b[n] != n ; h *= 2 ){
		SAComp comp(h,g);
		sort(v.begin(),v.end(),comp);
		for(int i = 0 ; i < n ; i++) b[i+1] = b[i] + comp(v[i],v[i+1]);
		for(int i = 0 ; i < n + 1 ; i++ ) g[v[i]] = b[i];
	}
	return v;
}

vector<int> seg[100010];

// v??\???
int get(int x,int v){
	x+=2;
	int ans = 0;
	for(int i = x ; i > 0 ; i -= i & -i ){
		ans += upper_bound(seg[i].begin(),seg[i].end(),v) - seg[i].begin();
	}
	return ans;
}
void add(int x,int v){
	x+=2;
	for(int i = x ; i < 100010 ; i += i & -i ){
		seg[i].push_back(v);
	}
}


int N;

bool bad(string &s,int p,string &t){
	return s.substr(p,t.size()) < t;
}
bool good(string &s,int p,string &t){
	return s.substr(p,t.size()) == t;
}
pair<int,int> getSeg(string &s,const vector<int> &sa,string &t){
	int l = 0 , r = sa.size() - 1;
	while( l != r ){
		int m = (l+r) / 2;
		if( bad(s,sa[m],t) ) l = m+1;
		else r = m;
	}
	if( !good(s,sa[l],t) ) return {-1,-1};
	int startPos = l;
	r = sa.size() - 1;
	while( l != r ){
		int m = (l+r+1) / 2;
		if( good(s,sa[m],t) ) l = m;
		else r = m - 1;
	}
	int endPos = r;
	return {startPos,endPos};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;
	auto sa = buildSA(S);
	for(int i = 0 ; i < sa.size() ; i++){
		add(i,sa[i]);
	}
	for(int i = 0 ; i < 100010 ; i++)
		sort(seg[i].begin(),seg[i].end());
	//for(int i = 0 ; i < sa.size() ; i++){
	//	cout << i << ": " << S.substr(sa[i]) << endl;
	//}
	int Q;
	cin >> Q;
	for(int i = 0 ; i < Q ; i++){
		int l,r;
		string m;
		cin >> l >> r >> m;
		--l;
		r -= m.size() - 1;
		auto seg = getSeg(S,sa,m);
		//cerr << "[" << seg.first << " " << seg.second << "]" << "|" << l << " " << r << endl;
		if( l > r || seg.first == -1 ) cout << 0 << endl;
		else{
			cout << get(seg.second,r) - get(seg.first-1,r) - get(seg.second,l) + get(seg.first-1,l) << endl;
		}
	}

}