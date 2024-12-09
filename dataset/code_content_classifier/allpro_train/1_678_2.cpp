#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
struct Node{
  char label;
  Node *left, *right;
  Node(char label) : label(label), left(NULL), right(NULL) {}
};
struct Result{
  Node* value;
  int p;
  Result(Node* value, int p) :
    value(value), p(p) {}
};
struct Diag{
  char label;
  Diag *left, *right;
  int ld, rd;
  vector< pair<int, int> > v;
  Diag(char label) :
    label(label), left(NULL), right(NULL), ld(0), rd(0), v(0) {}
};

Result parse(const string& s, int p){
  Node* node = new Node(s[p]);
  if(s[p + 1] == '('){
    Result l_res = parse(s, p + 2);
    node->left = l_res.value;
    if(s[l_res.p] == ','){ //A(B, C)
      Result r_res = parse(s, l_res.p + 1);
      node->right = r_res.value;
      assert(s[r_res.p] == ')');
      return Result(node, r_res.p + 1);
    }else if(s[l_res.p] == ')'){ //A(B)
      return Result(node, l_res.p + 1);
    }else{ // exception
      assert(false);
    }
  }else{
    return Result(node, p + 1);
  }
}
void print(Node* p){
  printf("label: %c ", p->label);
  if(p->left){
    printf("left: %c ", p->left->label);
  }
  if(p->right){
    printf("right: %c ", p->right->label);
  }
  cout<<endl;
  if(p->left){
    print(p->left);
  }
  if(p->right){
    print(p->right);
  }
}
bool is_0ary(Node* p){ return (!p->left && !p->right); }
bool is_1ary(Node* p){ return ( p->left && !p->right); }
bool is_2ary(Node* p){ return ( p->left &&  p->right); }
bool is_0ary(Diag* p){ return (!p->left && !p->right); }
bool is_1ary(Diag* p){ return ( p->left && !p->right); }
bool is_2ary(Diag* p){ return ( p->left &&  p->right); }
Diag* make_diag(Node* p){
  if(is_0ary(p)){
    Diag* d = new Diag(p->label);
    return d;
  }else if(is_1ary(p)){
    Diag* d = new Diag(p->label);
    d->left = make_diag(p->left);
    d->v.push_back(make_pair(0, 0));
    d->v.insert(d->v.end(), d->left->v.begin(), d->left->v.end());
    return d;
  }else if(is_2ary(p)){
    Diag* d = new Diag(p->label);
    d->left = make_diag(p->left);
    d->right = make_diag(p->right);
    int len = 3;
    for(int i = 0; i < min(d->left->v.size(), d->right->v.size()); i++){
        len = max(len, 3 + d->left->v[i].second - d->right->v[i].first);
      if(i + 1 < d->right->v.size()) 
        len = max(len, 2 + d->left->v[i].second - d->right->v[i + 1].first);
      if(i + 1 < d->left->v.size()) 
        len = max(len, 2 + d->left->v[i + 1].second - d->right->v[i].first);
    }
    if(d->left->v.empty() && d->right->v.size()) len = max(len, 2 - d->right->v[0].first);
    if(d->right->v.empty() && d->left->v.size()) len = max(len, 2 + d->left->v[0].second);
    int mid = (len - 1) / 2;
    d->ld = -mid;
    d->rd = len + d->ld - 1;
    d->v.push_back(make_pair(d->ld, d->rd));
    for(int i = 0; i < max(d->left->v.size(), d->right->v.size()); i++){
      int ld = INF, rd = -INF;
      if(i < d->left->v.size()) ld = min(ld, d->left->v[i].first + d->ld);
      if(i < d->left->v.size()) rd = max(rd, d->left->v[i].second + d->ld);
      if(i < d->right->v.size()) ld = min(ld, d->right->v[i].first + d->rd);
      if(i < d->right->v.size()) rd = max(rd, d->right->v[i].second + d->rd);
      d->v.push_back(make_pair(ld, rd));
    }
    return d;
  }else { // exception
    assert(false);
  }
}
void print(Diag* p){
  printf("label: %c ", p->label);
  if(is_0ary(p)) printf("ary:0 ");
  if(is_1ary(p)) printf("ary:1 ld: %d ", p->ld);
  if(is_2ary(p)) printf("ary:2 ld: %d rd: %d ", p->ld, p->rd);
  REP(i, p->v.size()) printf("(%d, %d) ", p->v[i].first, p->v[i].second);
  cout<<endl;
  if(p->left){
    print(p->left);
  }
  if(p->right){
    print(p->right);
  }
}
const int SW = 500;
const int SH = 200;
char str[SH][SW];
void make_str(int y, int x, Diag* p){
  assert(y >= 0);
  assert(y < SH);
  str[y * 2][x] = p->label;
  if(is_0ary(p)){
  }else if(is_1ary(p)){
    str[y * 2 + 1][x] = '-';
    make_str(y + 1, x, p->left);
  }else if(is_2ary(p)){
    for(int dx = p->ld; dx <= p->rd; dx++){
      assert(x + dx >= 0);
      assert(x + dx < SW);
      str[y * 2 + 1][x + dx] = '-';
    }
    make_str(y + 1, x + p->ld, p->left);
    make_str(y + 1, x + p->rd, p->right);
  }else {
    assert(false);
  }
}
void output(){
  for(int y = SH - 1; y >= 0; y--){
    int ex = SW;
    while(ex - 1 >= 0 && str[y][ex - 1] == ' ') ex--;
    if(ex == 0) continue;
    REP(x, ex) putchar(str[y][x]);
    putchar('\n');
  }
}

int main(){
  vector<string> BUTS;
  string s, tmp;
  while(cin >> tmp){
    s += tmp;
  }
  REP(i, s.size()) if(s[i] == ';') s[i] = ' ';
  REP(i, s.size()) if(s[i] == '.') s[i] = ' ';
  stringstream ss(s);
  while(ss >> tmp){
    BUTS.push_back(tmp);
  }
  REP(i, BUTS.size()){
    Result res = parse(BUTS[i], 0);
    Node* root = res.value;
    assert(res.p == BUTS[i].size());
    printf("%d:\n", i + 1);
    //cout<<BUTS[i]<<endl;
    //print(root);
    Diag* d = make_diag(root);
    //print(d);
    REP(y, SH) REP(x, SW) str[y][x] = ' ';
    int minld = 0;
    REP(i, d->v.size()) minld = min(minld, d->v[i].first);
    make_str(0, -minld, d);
    output();
  }
  return 0;
}