#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF INT_MAX
#define LINF LLONG_MAX
#define all(vec) vec.begin(), vec.end()
#define FILEINPUT freopen("inputCNB.txt", "r", stdin);
#define FILEOUTPUT freopen("ouputCNB.txt", "w", stdout);
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define FORD(i, m, n) for(int i=m; i>=n; i--)
#define FastIO cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define reset(A) memset(A, 0, sizeof(A))
#define debug cerr << "debug: "
using namespace std;
/******* LIBRARY and DEFINE *******/
template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){return os << "(" << p.f << " " << p.s << ")";};
template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/
const int MAXN = 3e5 + 5;
const int mod = 1e9 + 7;
/********** CONSTANT *********/
int ST[MAXN << 2];
int A[MAXN];

void build(int root, int left, int right){
	if(left == right){
		ST[root] = A[left];
		return;
	}
	int mid = (left + right) >> 1;
	build(root << 1, left, mid);
	build(root << 1 ^ 1, mid + 1, right);
	ST[root] = min(ST[root << 1], ST[root << 1 ^ 1]);
}

int getMin(int root, int left, int right, int l, int r){
	if(left > r || right < l) return INF;
	if(left >= l && right <= r) return ST[root];
	int mid = (left + right) >> 1;
	return min(getMin(root << 1, left, mid, l, r), getMin(root << 1 ^ 1, mid + 1, right, l, r));
}

void solution(){
	reset(ST);
	int n;
	cin >> n;
	int MIN = INF;
	map<int, int> cnt;
	FOR(i, 1, n + 1) cin >> A[i], cnt[A[i]]++, MIN = min(MIN, A[i]);
	build(1, 1, n);
	bool check = [&]() {
		if(cnt.size() != n) return false;
		FOR(i, 1, n + 1) if(cnt[i] == 0) return false;
		return true;
	}();
	string ans = check? "1" : "0";
	int low = 1, high = n;
	int index = 1;
	string res;
	int count = 0;
	while(low < high && index < n - 1){
		if(A[low] == index) low++;
		else if(A[high] == index) high--;
		else break;
		int m = getMin(1, 1, n, low, high);
//		cout << m << endl;
		if(m != index + 1) break;
		index++;
		count++;
	}
	FOR(i, 0, n - count - 2) ans += '0';
	FOR(i, 0, count) ans += '1';
	if(n > 1) ans += MIN == 1? '1' : '0';
	cout << ans << endl;


}


/*******************************/
		
/******** MAIN FUNCTION *********/
int main(){
	#ifdef testIN
		FILEINPUT;
	#endif
	#ifdef testOUT 
		FILEOUTPUT;
	#endif
	
	FastIO;

	int test = 1;	
	cin >> test; cin.ignore();	
	while(test--) solution();	
	return 0;
}
/********** I'mAlone ***********/
/******** CAN NGOC BINH **********/