#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<ll,ll> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;
template <class T>
struct avl_tree {
  struct node {
    T key;
    int size, height;
    node *child[2];
    node(const T &key) : key(key), size(1), height(1) {
      child[0] = child[1] = 0; }
  } *root;
  typedef node *pointer;
  avl_tree() { root = NULL; }

  pointer find(const T &key) { return find(root, key); }
  node *find(node *t, const T &key) {
    if (t == NULL) return NULL;
    if (key == t->key) return t;
    else if (key < t->key) return find(t->child[0], key);
    else                   return find(t->child[1], key);
  }
  void insert(const T &key) { root = insert(root, new node(key)); }
  node *insert(node *t, node *x) {
    if (t == NULL) return x;
    if (x->key <= t->key) t->child[0] = insert(t->child[0], x);
    else                  t->child[1] = insert(t->child[1], x);
    t->size += 1;
    return balance(t);
  }
  void erase(const T &key) { root = erase(root, key); }
  node *erase(node *t, const T &x) {
    if (t == NULL) return NULL;
    if (x == t->key) {
      return move_down(t->child[0], t->child[1]);
    } else {
      if (x < t->key) t->child[0] = erase(t->child[0], x);
      else            t->child[1] = erase(t->child[1], x);
      t->size -= 1;
      return balance(t);
    }
  }
  node *move_down(node *t, node *rhs) {
    if (t == NULL) return rhs;
    t->child[1] = move_down(t->child[1], rhs);
    return balance(t);
  }
#define sz(t) (t ? t->size : 0)
#define ht(t) (t ? t->height : 0)
  node *rotate(node *t, int l, int r) {
    node *s = t->child[r];
    t->child[r] = s->child[l];
    s->child[l] = balance(t);
    if (t) t->size = sz(t->child[0]) + sz(t->child[1]) + 1;
    if (s) s->size = sz(s->child[0]) + sz(s->child[1]) + 1;
    return balance(s);
  }
  node *balance(node *t) {
    for (int i = 0; i < 2; ++i) {
      if (ht(t->child[!i]) - ht(t->child[i]) < -1) {
        if (ht(t->child[i]->child[!i]) - ht(t->child[i]->child[i]) > 0)
          t->child[i] = rotate(t->child[i], i, !i);
        return rotate(t, !i, i);
      }
    }
    if (t) t->height = max(ht(t->child[0]), ht(t->child[1])) + 1;
    if (t) t->size = sz(t->child[0]) + sz(t->child[1]) + 1;
    return t;
  }
  pointer rank(int k) const { return rank(root, k); }
  pointer rank(node *t, int k) const {
    if (!t) return NULL;
    int m = sz(t->child[0]);
    if (k  < m) return rank(t->child[0], k);
    if (k == m) return t;
    if (k  > m) return rank(t->child[1], k - m - 1);
  }
};
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n, c; cin >> n >> c;
	avl_tree<pi> tree;
	vector<ll> pt(n);
	rep(i, n) tree.insert(pi(0, i));
	
	while(c--){
		int x, y, z; cin >> x >> y; y--;
		if(x == 0){
			cin >> z;
			tree.erase(pi(-pt[y], y));
			pt[y] += z;
			tree.insert(pi(-pt[y], y));
		}
		else{
			auto node = tree.rank(y)->key;
			cout << node.second + 1 << " " << -node.first << endl;
		}
	}
	return 0;
}
