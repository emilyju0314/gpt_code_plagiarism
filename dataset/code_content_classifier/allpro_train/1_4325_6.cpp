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
void replace(string& s, const string& from, const string& to){
  string::size_type pos = s.find(from);
  while(pos != string::npos){
    s.replace(pos, from.size(), to);
    pos = s.find(from, pos + to.size());
  }
}
struct Result{
  string value;
  int p;
  Result(string s, int p) : value(s), p(p){}
};
map<int, vector<Result> > memo[1000];
bool used[1000];
map<int, vector<Result> > expr(const string& s, int p){
  int P = p; 
  assert(P >= 0 && P < 1000);
  if(used[P]) return memo[P];
  assert(s[p] == '[');
  p++;
  queue<Result> que;
  map<int, vector<Result> >& res = memo[P];
  vector<int> cnt(s.size() + 1);
  if(isupper(s[p])){
    string word;
    while(isupper(s[p])) word += s[p++];
    Result r("(" + word, p);
    que.push(r);
    res[r.p].push_back(Result(r.value + ")", r.p));
  }else{
    map<int, vector<Result> > rvm = expr(s, p);
    FORIT(it_, rvm)FORIT(it, it_->second){
      que.push(Result("(" + it->value, it->p));
      res[it->p].push_back(Result("(" + it->value + ")", it->p));
    }
  }
  while(!que.empty()){
    Result r = que.front(); que.pop();
    if(s[r.p] == ','){
      if(s[r.p + 1] == '['){
        map<int, vector<Result> > rvm = expr(s, r.p + 1);
        FORIT(it_, rvm) FORIT(it, it_->second) if(cnt[it->p] < 2){
          cnt[it->p]++;
          que.push(Result(r.value + " " + it->value, it->p));
        }
      }else if(isupper(s[r.p + 1])){
        string word;
        while(isupper(s[r.p + 1])) word += s[++r.p];
        if(cnt[r.p + 1] < 2){
          cnt[r.p + 1]++;
          que.push(Result(r.value + " " + word, r.p + 1));
        }
      }else{
        assert(false);
      }
    }else if(s[r.p] == '&'){
      if(s[r.p + 1] == '['){
        map<int, vector<Result> > rvm = expr(s, r.p + 1);
        FORIT(it_, rvm) FORIT(it, (it_->second)) if(res[it->p].size() < 2){
          res[it->p].push_back(Result(r.value + " " + it->value + ")", it->p));
        }
      }else if(isupper(s[r.p + 1])){
        string word;
        while(isupper(s[r.p + 1])) word += s[++r.p];
        if(res[r.p + 1].size() < 2){
          res[r.p + 1].push_back(Result(r.value + " " + word + ")", r.p + 1));
        }
      }else{
        assert(false);
      }
    }else {
      assert(r.p == (int)s.size());
    }
  }
  used[P] = true;
  return res;
}
int main(){
  int N;
  cin >> N;
  cin.ignore();
  while(N--){
    string s;
    REP(i, 1000) memo[i].clear();
    REP(i, 1000) used[i] = false;
    getline(cin, s);
    replace(s, "a list of", "[");
    replace(s, "and", "&");
    replace(s, " ", "");
    map<int, vector<Result> > rvm = expr(s, 0);
    if(rvm[s.size()].size() == 1){
      cout << rvm[s.size()][0].value << endl;
    }else if(rvm[s.size()].size() > 1){
      cout << "AMBIGUOUS" << endl;
    }else{
      cout << "NULL"<<endl;
    }
  }
  return 0;
}