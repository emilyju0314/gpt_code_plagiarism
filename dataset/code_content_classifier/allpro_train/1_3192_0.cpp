#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <map>
using namespace std;

const int inf = (int)1e9;

struct edge{
  int to;
  int cost;
  edge(int _to, int _cost) : to(_to), cost(_cost){};
};

struct Path{
  int cost;
  vector<int> nodes;
  Path(){}
  Path(int _cost, const vector<int> &_nodes) : cost(_cost), nodes(_nodes) {}
  void print() const{
    for(size_t i = 0; i < nodes.size(); i++)
      cout << nodes[nodes.size()- i - 1] + 1 << (i + 1 == nodes.size() ? '\n' : '-');
  }
  bool empty() const {return nodes.size() == 0; }
};


bool operator<(const Path &p1, const Path &p2) {
  if(p1.cost != p2.cost){
    return p1.cost > p2.cost;
  }else{
    int pos1 = p1.nodes.size();
    int pos2 = p2.nodes.size();
    while(--pos1 >= 0 && --pos2 >= 0 && p1.nodes[pos1] == p2.nodes[pos2]);
    if(p1.nodes[pos1] != p2.nodes[pos2]){
      return p1.nodes[pos1] > p2.nodes[pos2];
    }else{
      return pos1 > pos2;
    }
  }
}

Path operator+(const Path &p1, const Path &p2){
  assert(!p1.empty() && !p2.empty() && p1.nodes.back() == p2.nodes[0]);
  vector<int> nodes = p1.nodes;
  for(size_t i = 1; i < p2.nodes.size(); i++){
    nodes.push_back(p2.nodes[i]);
  }
  return Path(p1.cost + p2.cost, nodes);
}

typedef vector<vector<edge> > Graph;

Path make_path(const Graph &graph, int s, int t,
               const vector<int> &prevv,
               const vector<int> &preve){
  int cost = 0;
  vector<int> nodes;
  for(int v = t; s != v; v = prevv[v]){
    nodes.push_back(v);
    cost += graph[prevv[v]][preve[v]].cost;
  }
  
  nodes.push_back(s);
  reverse(nodes.begin(), nodes.end());
  return Path(cost, nodes);
}


Path dijkstra(const Graph &graph, int s, int t,
              vector<int> *ignored_nodes = NULL,
              vector<int> *ignored_edges = NULL){
  
  int n = graph.size();
  vector<int> dist(n, inf);
  vector<int> prevv(n, inf);
  vector<int> preve(n, inf);
  vector<int> ig_edges(n, 0);
  
  if(ignored_nodes){
    for(size_t i = 0; i < ignored_nodes->size(); i++){
      dist[(*ignored_nodes)[i]] = -inf;
    }
  }
  
  if(ignored_edges){
    for(size_t i = 0; i < ignored_edges->size(); i++){
      ig_edges[(*ignored_edges)[i]] = 1;
    }
  }

  
  priority_queue<pair<int, int> > que;
  dist[s] = 0;  
  que.push(make_pair(0, s));
  
  while(!que.empty()){
    pair<int, int> p = que.top();  que.pop();
    int cost = -p.first;
    int v = p.second;
    
    if(cost > dist[v]) continue;
    // shortest path found
    
    if(v == t){
      return make_path(graph, s, t, prevv, preve);
    }
    
    for(size_t i = 0; i < graph[v].size(); i++){
      const edge &e = graph[v][i];
      int tmp = e.cost + dist[v];
      if(v == s && ig_edges[i]) continue; // e is ignored edge
      if(tmp < dist[e.to] || (tmp == dist[e.to] && v < prevv[e.to])){
        dist[e.to] = tmp;
        prevv[e.to] = v;
        preve[e.to] = i;
        que.push(make_pair(-tmp, e.to));
      }
    }
  }
  // unfound
  return Path();
}

class PsuedoTree{
  struct node_t{
    int v;
    map<int, node_t*> ch;
    node_t(int s) : v(s) {}
    ~node_t(){
      for(map<int, node_t*>::iterator iter = ch.begin(); iter != ch.end(); iter++){
        delete iter->second;
      }
    }
  };
  
  node_t *root;
public:
  PsuedoTree(const Path &p){
    assert(!p.empty());
    root = new node_t(p.nodes[0]);
    add_path(p);
  }
  
  ~PsuedoTree(){ delete root; }
  
  void add_path(const Path &p){
    node_t *t = root;
    const vector<int> &nodes = p.nodes;
    assert(nodes[0] == t->v);
    
    vector<int> ignored_nodes;
    
    for(size_t i = 1; i < p.nodes.size(); i++){
      if(t->ch.find(nodes[i]) == t->ch.end()){
        t->ch[nodes[i]] = new node_t(nodes[i]);
      }
      t = t->ch[nodes[i]];
      
    }
  }
  
  void generate_candidate_path(const Graph &graph, int s, int t,
                               const Path &p,
                               priority_queue<Path> &path_que){
    int sum = 0;
    node_t *pt_node = root;
    vector<int> ignored_nodes;
    
    for(size_t i = 0; i + 1 < p.nodes.size(); i++){
      int v = p.nodes[i];
      vector<int> ignored_edges;
      
      for(size_t j = 0; j < graph[v].size(); j++){      
        if(pt_node->ch.find(graph[v][j].to) != pt_node->ch.end()){
          ignored_edges.push_back(j);
        }
      }
      
      ignored_nodes.push_back(v);
      Path candidate_path = dijkstra(graph, v, t, &ignored_nodes, &ignored_edges);
      if(!candidate_path.empty()){
        candidate_path = Path(sum, ignored_nodes) +  candidate_path;
        add_path(candidate_path);
        path_que.push(candidate_path);
      }
      
      pt_node = pt_node->ch[p.nodes[i+1]];
      assert(pt_node != NULL);
      
      for(size_t j = 0; j < graph[v].size(); j++)
        if(graph[v][j].to == p.nodes[i+1]) 
          sum += graph[v][j].cost;
    }
  }
};


vector<Path> topKShortestPath(const Graph &graph, int s, int t, int k){
  vector<Path> kshort(k);

  // cerr << "start computation" << endl;
  Path p = dijkstra(graph, s, t);
  if(p.empty()) return vector<Path>();
  
  PsuedoTree pt(p);
  priority_queue<Path> path_que;
  
  path_que.push(p);
  for(int i = 0; i < k; i++){
    if(path_que.empty()) return vector<Path>();

    kshort[i] = path_que.top(); path_que.pop();
    pt.generate_candidate_path(graph, s, t, kshort[i], path_que);
  }
  
  return kshort;
}
  

int main(){
  int n, m, k, a, b, x, y, d;
  while(cin >> n >> m >> k >> a >> b && (n + m + k + a + b) > 0){
    
    Graph g(n);
    for(int i = 0; i < m; i++){
      cin >> x >> y >> d;
      x--, y--;
      g[y].push_back(edge(x, d));
    }

    vector<Path> paths = topKShortestPath(g, --b, --a, k);
    if(paths.size() == 0){
      cout << "None" << endl;
    }else{
      paths[k-1].print();
    }
  }
  return 0;
}