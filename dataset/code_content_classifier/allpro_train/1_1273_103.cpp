#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Edge {
  int from, to;
  T cap, flow;
  int index;
  Edge(int from, int to, T cap, T flow, int index)
      : from(from), to(to), cap(cap), flow(flow), index(index) {}
};
template <class T>
struct PushRelabel {
  int n;
  vector<vector<Edge<T>>> adj;
  vector<T> excess;
  vector<int> dist, count;
  vector<bool> active;
  vector<vector<int>> B;
  int b;
  queue<int> Q;
  const int source = 0, sink = 1;
  PushRelabel() : n(2), adj(2) {}
  int add_vertex() {
    adj.push_back({});
    return n++;
  }
  void add_edge(int from, int to, int cap) {
    adj[from].push_back(Edge<T>(from, to, cap, 0, int(adj[to].size())));
    if (from == to) {
      adj[from].back().index++;
    }
    adj[to].push_back(Edge<T>(to, from, 0, 0, int(adj[from].size()) - 1));
  }
  void Enqueue(int v) {
    if (!active[v] && excess[v] > 0 && dist[v] < n) {
      active[v] = true;
      B[dist[v]].push_back(v);
      b = max(b, dist[v]);
    }
  }
  void Push(Edge<T> &e) {
    T amt = min(excess[e.from], e.cap - e.flow);
    if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) {
      e.flow += amt;
      adj[e.to][e.index].flow -= amt;
      excess[e.to] += amt;
      excess[e.from] -= amt;
      Enqueue(e.to);
    }
  }
  void Gap(int k) {
    for (int v = 0; v < n; v++)
      if (dist[v] >= k) {
        count[dist[v]]--;
        dist[v] = max(dist[v], n);
        count[dist[v]]++;
        Enqueue(v);
      }
  }
  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = n;
    for (auto e : adj[v])
      if (e.cap - e.flow > 0) {
        dist[v] = min(dist[v], dist[e.to] + 1);
      }
    count[dist[v]]++;
    Enqueue(v);
  }
  void Discharge(int v) {
    for (auto &e : adj[v]) {
      if (excess[v] > 0) {
        Push(e);
      } else {
        break;
      }
    }
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) {
        Gap(dist[v]);
      } else {
        Relabel(v);
      }
    }
  }
  T maxflow() {
    dist = vector<int>(n, 0), excess = vector<T>(n, 0),
    count = vector<int>(n + 1, 0), active = vector<bool>(n, false),
    B = vector<vector<int>>(n), b = 0;
    for (auto &e : adj[source]) {
      excess[source] += e.cap;
    }
    count[0] = n;
    Enqueue(source);
    active[sink] = true;
    while (b >= 0) {
      if (!B[b].empty()) {
        int v = B[b].back();
        B[b].pop_back();
        active[v] = false;
        Discharge(v);
      } else {
        b--;
      }
    }
    return excess[sink];
  }
};
int main() {
  ios::sync_with_stdio(false);
  auto network = PushRelabel<int>();
  int n;
  cin >> n;
  auto vertices = array<vector<int>, 2>{};
  for (auto &vs : vertices) vs = vector<int>(4 * n);
  const function<int(int, int, int, bool)> build =
      [&](const int i, const int l, const int r, const bool direction) {
        const auto v = vertices[direction][i] = network.add_vertex();
        if (r - l == 1) {
          if (direction)
            network.add_edge(network.source, v, 1);
          else
            network.add_edge(v, network.sink, 1);
        } else {
          const auto m = (l + r) / 2;
          const auto w1 = build(2 * i, l, m, direction);
          const auto w2 = build(2 * i + 1, m, r, direction);
          if (direction) {
            network.add_edge(w1, v, n);
            network.add_edge(w2, v, n);
          } else {
            network.add_edge(v, w1, n);
            network.add_edge(v, w2, n);
          }
        }
        return v;
      };
  for (auto direction : {true, false}) build(1, 0, n, direction);
  using Segment = array<int, 2>;
  using Rectangle = array<Segment, 2>;
  const auto add_rectangle = [&](const Rectangle q) {
    if (q[0][0] == q[0][1] || q[1][0] == q[1][1]) return;
    const auto v = network.add_vertex();
    for (const auto direction : {true, false}) {
      const auto ql = q[direction][0], qr = q[direction][1];
      const function<void(int, int, int)> connect =
          [&](const int i, const int l, const int r) {
            if (ql >= r || l >= qr)
              return;
            else if (ql <= l && r <= qr) {
              if (direction)
                network.add_edge(vertices[direction][i], v, n);
              else
                network.add_edge(v, vertices[direction][i], n);
            } else {
              const auto m = (l + r) / 2;
              connect(2 * i, l, m);
              connect(2 * i + 1, m, r);
            }
          };
      connect(1, 0, n);
    }
  };
  int q;
  cin >> q;
  struct Event {
    bool type;
    int x;
    Segment y;
  };
  auto events = vector<Event>();
  for (auto i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    events.push_back({true, x1, {y1, y2 + 1}});
    events.push_back({false, x2 + 1, {y1, y2 + 1}});
  }
  events.push_back({false, 0, {0, n}});
  events.push_back({true, n, {0, n}});
  const auto event_compare = [](const Event a, const Event b) {
    if (a.x != b.x)
      return a.x < b.x;
    else
      return a.type < b.type;
  };
  sort(begin(events), end(events), event_compare);
  struct PartialRectangle {
    int x1;
    Segment y;
  };
  const auto rect_compare = [](const PartialRectangle a,
                               const PartialRectangle b) {
    return a.y[0] < b.y[0];
  };
  auto active = set<PartialRectangle, decltype(rect_compare)>(rect_compare);
  for (const auto e : events) {
    if (e.type) {
      auto to_insert = vector<PartialRectangle>();
      auto i = active.lower_bound({0, e.y[0]});
      if (i != begin(active) && prev(i)->y[1] > e.y[0]) i = prev(i);
      while (i != end(active) && i->y[0] < e.y[1]) {
        if (i->y[0] < e.y[0]) to_insert.push_back({e.x, {i->y[0], e.y[0]}});
        if (e.y[1] < i->y[1]) to_insert.push_back({e.x, {e.y[1], i->y[1]}});
        add_rectangle({{{i->x1, e.x}, i->y}});
        active.erase(i++);
      }
      for (const auto r : to_insert) active.insert(r);
    } else
      active.insert({e.x, e.y});
  }
  cout << network.maxflow() << endl;
}
