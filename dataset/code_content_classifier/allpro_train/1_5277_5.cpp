#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int,int> pint;

#define DE 1
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define ALL(s) (s).begin(),(s).end()
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define EACH(i,s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl

template<class T1, class T2> ostream& operator<<(ostream &s, pair<T1,T2> P){return s<<'<'<<P.first<<", "<<P.second<<'>';}
template<class T> ostream& operator<<(ostream &s, vector<T> P) {s<<"{ ";for(int i=0;i<P.size();++i){if(i>0)s<<", ";s<<P[i];}return s<<" }"<<endl;}
template<class T1, class T2> ostream& operator<<(ostream &s, map<T1,T2> P) {s<<"{ ";for(__typeof__(P.begin()) it=P.begin();it!=P.end();++it){if(it!=P.begin())s<<", ";s<<'<'<<it->first<<"->"<<it->second<<'>';}return s<<" }"<<endl;}



const int MAX_L = 510;
const int MAX_R = 510;

struct Graph {
    static const int MAX_V_ = ::MAX_L;
    int L;
    vector<int> list[MAX_V_];
    
    void init(int n = 0) {L = n; for (int i = 0; i < MAX_V_; ++i) list[i].clear();}
    inline vector<int>& operator [] (int i) {return list[i];}
    friend ostream& operator << (ostream& s, const Graph& G) {for (int i = 0; i < G.L; ++i) {s << i << " : " << G.list[i];}return s;}
    
    void addedge(int from, int to) {
        list[from].push_back(to);
    }
} G;

int L = 0;
bool seen[MAX_L];
bool matched[MAX_L];
int level[MAX_L];
int matching[MAX_R];

void hobfs(Graph &G) {
    queue<int> que;
    for (int left = 0; left < L; ++left) {
        level[left] = -1;
        if (!matched[left]) {
            que.push(left);
            level[left] = 0;
        }
    }
    level[L] = L;
    while (!que.empty()) {
        int left = que.front();
        que.pop();
        for (int i = 0; i < G[left].size(); ++i) {
            int right = G[left][i];
            int next = matching[right];
            if (level[next] == -1) {
                level[next] = level[left] + 1;
                que.push(next);
            }
        }
    }
}

bool hodfs(Graph &G, int left) {
    if (left == L) return true;
    if (seen[left]) return false;
    seen[left] = true;
    for (int i = 0; i < G[left].size(); ++i) {
        int right = G[left][i];
        int next = matching[right];
        if (level[next] > level[left] && hodfs(G, next)) {
            matching[right] = left;
            return true;
        }
    }
    return false;
}

int Hopcroft_Karp(Graph &G) {
    L = G.L;
    for (int i = 0; i < MAX_R; ++i) matching[i] = L;
    memset(matched, 0, sizeof(matched));
    
    int res = 0;
    while (true) {
        hobfs(G);
        memset(seen, 0, sizeof(seen));
        bool finished = true;
        for (int left = 0; left < L; ++left) {
            if (!matched[left] && hodfs(G, left)) {
                matched[left] = true;
                ++res;
                finished = false;
            }
        }
        if (finished) break;
    }
    return res;
}


int N, M;

int main() {
    cin >> N >> M;
    G.init(N);
    for (int i = 0; i < N; ++i) {
        int num; scanf("%d", &num);
        for (int j = 0; j < num; ++j) {
            int a;
            scanf("%d", &a);
            --a;
            G.addedge(i, a);
        }
    }
    int flow = Hopcroft_Karp(G);
    
    if (M == flow) cout << "Bob" << endl;
    else cout << "Alice" << endl;
    
    return 0;
}
