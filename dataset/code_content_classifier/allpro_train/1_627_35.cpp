#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl








const int maxn = 2001;
const int inf = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a, T b) {
    return uniform_int_distribution<T>(a, b)(rng);
}

int n;
set<int> g[maxn];

void add_edge(int u, int v) {
    g[u].insert(v);
    g[v].insert(u);
}


int Q;
vector<int> ask(int u) {
    Q++;
    if (Q > (n+1)/2) {
	return {};
    }
    
    cout<<"? "<<u<<endl;
    vector<int> res(n+1);
    for (int i=1; i<=n; i++) {
	cin>>res[i];
    }
    return res;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;

    vector<vector<int>> dist(2);
    
    auto res = ask(1);
    for (int i=1; i<=n; i++) {
	int d = res[i];
	if (d==1) {
	    add_edge(1,i);
	}
	dist[d&1].push_back(i);
    }

    int ub = (n+1)/2;
    if ((int)dist[0].size()-1 <= ub-1) {
	
    } else {
	swap(dist[0],dist[1]);
    }


    for (int at: dist[0]) {
	if (at==1) continue;
	auto res = ask(at);
	for (int i=1; i<=n; i++) {
	    if (res[i]==1) {
		add_edge(at,i);
	    }
	}
    }

    cout<<"!"<<endl;

    int edges = 0;
    for (int i=1; i<=n; i++) {
	for (int j: g[i]) {
	    if (i<j) {
		cout<<i<<" "<<j<<endl;
		edges++;
	    }
	}
    }

    assert(edges==n-1);
    return 0;
}
