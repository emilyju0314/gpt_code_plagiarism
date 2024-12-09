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

const int INF = 1L << 30;
typedef long long LL;
template<typename T> using V = std::vector<T>;
template<typename T> using VV = std::vector<std::vector<T>>;
template<typename T> using VVV = std::vector<std::vector<std::vector<T>>>;
template<class T> inline T ceil(T a, T b) { return (a + b - 1) / b; }
template<class T> inline void print(T x) { std::cout << x << std::endl; }
template<class T> inline void print_vec(const std::vector<T> &v) { for (int i = 0; i < v.size(); ++i) {  if (i != 0) {std::cout << " ";} std::cout << v[i];} std::cout << "\n"; }
template<class T> inline bool inside(T y, T x, T H, T W) {return 0 <= y and y < H and 0 <= x and x < W; }
template<class T> inline double euclidean_distance(T y1, T x1, T y2, T x2) { return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); }
template<class T> inline double manhattan_distance(T y1, T x1, T y2, T x2) { return abs(x1 - x2) + abs(y1 - y2); }



class MinimumCostFlow {
    struct Edge {
        const unsigned int to;    // 行き先のノードid
        long long flow;           // 流量
        const long long cap;      // 容量
        const long long cost;     // コスト
        const unsigned int rev;   // 逆辺のノードid
        const bool is_rev;        // 逆辺かどうか
        Edge(unsigned int to, long long flow, long long cap, long long cost, unsigned int rev, bool is_rev) : to(to), flow(flow), cost(cost), cap(cap), rev(rev), is_rev(is_rev) {
            assert(this->cap >= 0);
        }
    };

    const int num_node;                   // 頂点数
    std::vector<std::vector<Edge>> graph; // グラフの隣接リスト表現

public:
    MinimumCostFlow(int num_node) : num_node(num_node) {
        graph.resize(num_node);
    }

    // fromからtoへ向かう容量cap、コストcostの辺をグラフに追加する
    void add_edge(unsigned int from, unsigned int to, long long cap, long long cost) {
        graph.at(from).emplace_back(Edge(to, 0, cap, cost, graph.at(to).size(), false));
        graph.at(to).emplace_back(Edge(from, cap, cap, -cost, graph.at(from).size() - 1, true));
    }

    // sからtへの流量fの最小費用流を求める
    // 流せない場合は-1を返す
    bool run(const unsigned int source, const unsigned int sink, long long flow) {

        // 負閉路がある場合、先に負閉路にそって流しておく
        // ない場合はこの処理をskipしていい
        remove_negative_cycles(source);

        std::vector<int> prev_v(num_node, -1), prev_e(num_node, -1); // 直前の頂点と辺のidx
        std::vector<long long> potential(num_node, 0);               // ポテンシャル

        // 負の辺がある場合、ポテンシャルをベルマンフォードで求めておく
        // 負の辺がない場合はこの処理をskipしていい
        potential.assign(num_node, INT_MAX);
        potential.at(source) = 0;
        while (true) {
            bool updated = false;
            for (int v = 0; v < num_node; ++v) {
                for (auto &e : graph.at(v)) {
                    if (e.cap - e.flow > 0) {
                        if (potential.at(v) == INT_MAX) {
                            continue;
                        }
                        if (potential.at(e.to) > potential.at(v) + e.cost) {
                            potential.at(e.to) = potential.at(v) + e.cost;
                            updated = true;
                        }
                    }
                }
            }
            if (not updated) {
                break;
            }
        }

        while (flow > 0) {
            // ダイクストラ法を用いてポテンシャルを更新する
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
            std::vector<int> distance(num_node, INT_MAX);      // 最短距離

            distance.at(source) = 0;
            que.push(std::make_pair(0, source));
            while (not que.empty()) {
                std::pair<int, int> p = que.top(); // firstは最短距離、secondは頂点の番号
                que.pop();
                int v = p.second;
                if (distance.at(v) < p.first) {
                    continue;
                }
                for (int i = 0; i < graph.at(v).size(); ++i) {
                    Edge &e = graph.at(v).at(i);
                    if (e.cap - e.flow > 0 and
                        distance.at(e.to) > distance.at(v) + e.cost + potential.at(v) - potential.at(e.to)) {
                        distance.at(e.to) = distance.at(v) + e.cost + potential.at(v) - potential.at(e.to);
                        prev_v.at(e.to) = v;
                        prev_e.at(e.to) = i;
                        que.push(std::make_pair(distance.at(e.to), e.to));
                    }
                }
            }

            // これ以上流せない
            if (distance[sink] == INT_MAX) {
                return false;
            }
            for (int v = 0; v < num_node; ++v) {
                potential.at(v) += distance.at(v);
            }

            // source-sink間で流せる量を求める
            long long d = flow;
            for (int v = sink; v != source; v = prev_v.at(v)) {
                auto &e = graph.at(prev_v.at(v)).at(prev_e.at(v));
                d = std::min(d, e.cap - e.flow);
            }

            flow -= d;
            for (int v = sink; v != source; v = prev_v.at(v)) {
                Edge &e = graph.at(prev_v.at(v)).at(prev_e.at(v));
                e.flow += d;
                graph.at(v).at(e.rev).flow -= d;
            }
        }
        return true;
    }

    // 最小費用を取得する
    int minimum_cost_flow() {
        int cost = 0;
        for (int u = 0; u < graph.size(); ++u) {
            for (int i = 0; i < graph.at(u).size(); ++i) {
                Edge &e = graph.at(u).at(i);
                if (not e.is_rev) {
                    cost += e.flow * e.cost;
                }
            }
        }
        return cost;
    }

private:
    // 負閉路を除去する
    void remove_negative_cycles(const unsigned int source) {
        while (true) {
            // bellman-fordでsourceからの最短路を求める
            std::vector<int> prev_v(num_node, -1), prev_e(num_node, -1); // 直前の頂点と辺のidx
            std::vector<long long> distance(num_node, LONG_LONG_MAX);
            distance.at(source) = 0;

            int negative_cycle_idx = -1;
            for (int num = 0; num < num_node; ++num) {
                for (int u = 0; u < graph.size(); ++u) {
                    for (int i = 0; i < graph.at(u).size(); ++i) {
                        Edge &e = graph.at(u).at(i);

                        if (distance.at(u) == LONG_LONG_MAX) {
                            continue;
                        }

                        long long new_dist = distance.at(u) + e.cost;
                        if (e.cap - e.flow > 0 and distance.at(e.to) > new_dist) {
                            distance.at(e.to) = new_dist;
                            prev_v.at(e.to) = u;
                            prev_e.at(e.to) = i;

                            if (num == num_node - 1) {
                                negative_cycle_idx = e.to;
                            }
                        }
                    }
                }
            }

            // 負閉路がない
            if (negative_cycle_idx == -1) {
                return;
            }

            long long d = LONG_LONG_MAX;
            std::vector<bool> used(num_node, false);
            int u = negative_cycle_idx;
            while (not used.at(u)) {
                used.at(u) = true;
                const Edge &e = graph.at(prev_v.at(u)).at(prev_e.at(u));
                d = std::min(d, e.cap - e.flow);
                u = prev_v.at(u);
            }

            assert(d != 0);

            std::fill(used.begin(), used.end(), false);
            // 閉路の開始点から見ていく
            while (not used.at(u)) {
                used.at(u) = true;
                Edge &e = graph.at(prev_v.at(u)).at(prev_e.at(u));
                e.flow += d;
                graph.at(e.to).at(e.rev).flow -= d;
                u = prev_v.at(u);
            }
        }
    }
};

using namespace std;


int main() {

    int NAB, NBA;
    cin >> NAB >> NBA;

    vector<int> C1(NAB), D1(NAB), E1(NAB);
    vector<int> C2(NBA), D2(NBA), E2(NBA);
    set<int> ta, tb;
    FOR(i, 0, NAB) {
        cin >> C1[i] >> D1[i] >> E1[i];
        ta.insert(D1[i]);
        tb.insert(E1[i]);
    }
    FOR(i, 0, NBA) {
        cin >> C2[i] >> D2[i] >> E2[i];
        tb.insert(D2[i]);
        ta.insert(E2[i]);
    }

    vector<int> time_a(ALL(ta)), time_b(ALL(tb));
    int base = time_a.size();

    map<int, int> time_index_a, time_index_b;
    FOR(i, 0, time_a.size()) {
        time_index_a[time_a.at(i)] = i;
    }
    FOR(i, 0, time_b.size()) {
        time_index_b[time_b.at(i)] = base + i;
    }

    MinimumCostFlow mcf(time_a.size() + time_b.size());
    // A
    FOR(i, 0, time_a.size() - 1) {
        mcf.add_edge(time_index_a.at(time_a.at(i)), time_index_a.at(time_a.at(i + 1)), 10000, 0);
    }
    // B
    FOR(i, 0, time_b.size() - 1) {
        mcf.add_edge(time_index_b.at(time_b.at(i)), time_index_b.at(time_b.at(i + 1)), 10000, 0);
    }

    // A -> B
    FOR(i, 0, NAB) {
        mcf.add_edge(time_index_a.at(D1.at(i)), time_index_b.at(E1.at(i)), C1.at(i), -1);
    }
    // B -> A
    FOR(i, 0, NBA) {
        mcf.add_edge(time_index_b.at(D2.at(i)), time_index_a.at(E2.at(i)), C2.at(i), 0);
    }

    bool ok = mcf.run(time_index_a.at(time_a.at(0)), time_index_b.at(time_b.back()), 1);
    if (ok) {
        cout << -mcf.minimum_cost_flow() << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}
