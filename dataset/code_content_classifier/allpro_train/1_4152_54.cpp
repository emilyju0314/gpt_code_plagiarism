#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

typedef long long LL;
template<typename T> using V = std::vector<T>;
template<typename T> using VV = std::vector<std::vector<T>>;
template<typename T> using VVV = std::vector<std::vector<std::vector<T>>>;
template<class T> inline T ceil(T a, T b) { return (a + b - 1) / b; }
template<class T> inline void print(T x) { std::cout << x << std::endl; }
template<class T> inline bool inside(T y, T x, T H, T W) {return 0 <= y and y < H and 0 <= x and x < W; }
inline double distance(double y1, double x1, double y2, double x2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }

const int INF = 1L << 30;
const double EPS = 1e-9;
const std::string YES = "YES", Yes = "Yes", NO = "NO", No = "No";
const std::vector<int> dy = { 0, 1, 0, -1 }, dx = { 1, 0, -1, 0 };    // 4近傍（右, 下, 左, 上）

using namespace std;

// 最小費用流
class PrimalDual {
    struct Edge {
        const int to;         // 行き先のノードid
        int flow;             // 流量
        const int cap;        // 容量
        const int cost;       // コスト
        const int rev;        // 逆辺のノードid
        const bool is_rev;    // 逆辺かどうか
        Edge(int to, int flow, int cap, int cost, int rev, bool is_rev) : to(to), flow(flow), cost(cost), cap(cap), rev(rev), is_rev(is_rev) {
            assert(this->cap >= 0);
        }
    };

    const unsigned long V;       // 頂点数
    vector<vector<Edge>> graph;  // グラフの隣接リスト表現
    vector<int> h;               // ポテンシャル
    vector<int> dist;            // 最短距離
    vector<int> prevv, preve;    // 直前の頂点と辺

public:
    PrimalDual(unsigned long num_of_node) : V(num_of_node) {
        graph.resize(V);
        h.resize(V, 0);
        dist.resize(V);
        prevv.resize(V);
        preve.resize(V);
    }

    // fromからtoへ向かう容量cap、コストcostの辺をグラフに追加する
    void add_edge(int from, int to, int cap, int cost) {
        graph[from].emplace_back(Edge(to, 0, cap, cost, graph[to].size(), false));
        graph[to].emplace_back(Edge(from, cap, cap, -cost, graph[from].size() - 1, true));
    }

    // sからtへの流量fの最小費用流を求める(流せない場合は-1)
    // O(F|E|log |V|)かO(F|V|^2)
    int min_cost_flow(int s, int t, int f) {
        int res = 0;

        while (f > 0) {
            // ダイクストラ法を用いてhを更新する
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
            fill(dist.begin(), dist.end(), INT_MAX);
            dist[s] = 0;
            que.push(make_pair(0, s));
            while (not que.empty()) {
                pair<int, int> p = que.top();  // firstは最短距離, secondは頂点の番号
                que.pop();
                int v = p.second;
                if (dist[v] < p.first) {
                    continue;
                }
                for (int i = 0; i < graph[v].size(); ++i) {
                    Edge &e = graph[v][i];
                    if (e.cap - e.flow > 0 and dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;

                        preve[e.to] = i;
                        que.push(make_pair(dist[e.to], e.to));
                    }
                }
            }

            if (dist[t] == INT_MAX) {
                // これ以上流せない
                return -1;
            }
            for (int v = 0; v < V; v++) {
                h[v] += dist[v];
            }
            // s-t間最短路に沿って目一杯流す
            int d = f;
            for (int v = t; v != s; v = prevv[v]) {
                int rest = graph[prevv[v]][preve[v]].cap - graph[prevv[v]][preve[v]].flow;
                d = min(d, rest);
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = graph[prevv[v]][preve[v]];
                e.flow += d;
                graph[v][e.rev].flow -= d;
            }
        }
        return res;
    }

    // sからtへの流量fの最小費用流(流せない場合は-1)
    // 負のコストがあってもいい
    // O(F|V||E|)
    int min_cost_flow_bellmanford(int s, int t, int f) {
        int res = 0;
        while (f > 0) {
            // ベルマンフォード法により、s-t間最短路を求める
            fill(dist.begin(), dist.end(), INT_MAX);
            dist[s] = 0;
            bool update = true;
            while (update) {
                update = false;
                for (int v = 0; v < V; v++) {
                    if (dist[v] == INT_MAX) continue;
                    for (int i = 0; i < graph[v].size(); i++) {
                        Edge &e = graph[v][i];
                        int rest = e.cap - e.flow;
                        if (rest > 0 and dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }

            // これ以上流せない
            if (dist[t] == INF) {
                return -1;
            }

            // s-t間最短路に沿って目一杯流す
            int d = f;
            for (int v = t; v != s; v = prevv[v]) {
                int rest = graph[prevv[v]][preve[v]].cap - graph[prevv[v]][preve[v]].flow;
                d = min(d, rest);
            }

            f -= d;
            res += d * dist[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge &e = graph[prevv[v]][preve[v]];
                e.flow += d;
                graph[v][e.rev].flow -= d;
            }
        }
        return res;
    }

    // 水の流れたエッジを取得する
    set<pair<int, int>> get_used_edges() {
        set<pair<int, int>> used_edges;
        for (int from = 0; from < this->graph.size(); ++from) {
            for (Edge edge : graph[from]) {
                int flow = edge.flow;
                bool is_rev = edge.is_rev;

                if (not is_rev and flow > 0) {
                    int to = edge.to;
                    used_edges.insert(make_pair(from , to));
                }
            }
        }
        return used_edges;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    VV<int> add(N, V<int>(N)), del(N, V<int>(N)), field(N, V<int>(N));
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            cin >> add[i][j];
        }
    }
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            cin >> del[i][j];
        }
    }

    int cost = 0;
    FOR(i, 0, N) {
        string s;
        cin >> s;
        FOR(j, 0, N) {
            field[i][j] = (s[j] == 'o') ? 1 : 0;

            // 全部消す
            if (field[i][j] == 1) {
                cost += del[i][j];
            }
        }
    }

    PrimalDual pd(2 * N + 2);
    const int source = 2 * N;
    const int sink = source + 1;

    FOR(i, 0, N) {
        pd.add_edge(source, i, 1, 0);     // 行
        pd.add_edge(i + N, sink, 1, 0);   // 列
    }

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            if (field[i][j] == 1) {
                pd.add_edge(i, j + N, 1, -del[i][j]);
            }
            else {
                pd.add_edge(i, j + N, 1, add[i][j]);
            }
        }
    }

    print(cost + pd.min_cost_flow_bellmanford(source, sink, N));

    VV<int> field2(N, V<int>(N, 0));
    auto used_edges = pd.get_used_edges();
    FOE(edge, used_edges) {
        if (edge.first == source or edge.second == sink) { continue; }
        int y = edge.first;
        int x = edge.second - N;
        field2[y][x] = 1;
    }

    V<string> ans;
    FOR(y, 0, N) {
        FOR(x, 0, N) {
            if (field[y][x] == field2[y][x]) { continue; }
            if (field[y][x] == 1) {
                ans.emplace_back(to_string(y + 1) + " " + to_string(x + 1) + " erase");
            }
            else {
                ans.emplace_back(to_string(y + 1) + " " + to_string(x + 1) + " write");
            }
        }
    }

    print(ans.size());
    FOE(s, ans) {
        print(s);
    }

    return 0;
}
