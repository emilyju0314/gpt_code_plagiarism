#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
#include <complex>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
using W = double;
using P = complex<W>;
using L = pair<P,P>;
using Poly = vector<P>;

#define X real()
#define Y imag()

constexpr W EPS = 1e-8;

namespace std{
  bool operator <(const P &a, const P &b) {
    if (a.X != b.X) return a.X < b.X;
    return a.Y < b.Y;
  }
  bool cmp_y(const P &a, const P &b){
    return a.Y != b.Y ? a.Y < b.Y : a.X < b.X;
  }
}

W dot(P a, P b){ return a.X*b.X + a.Y*b.Y; }
W cross(P a, P b){ return a.X*b.Y - a.Y*b.X; }

int ccw(P a, P b, P c){
  b -= a, c -= a;
  if(cross(b,c) > +EPS) return +1;
  if(cross(b,c) < -EPS) return -1;
  if(dot(b,c) < -EPS) return 2;
  if(norm(b) < norm(c)-EPS) return -2;
  return 0;
}

bool is_cross(L a, L b){
  P af = a.first, as = a.second, bf = b.first, bs = b.second;
  return (ccw(af,as,bf)*ccw(af,as,bs) <= 0 and ccw(bf,bs,af)*ccw(bf,bs,as) <= 0);
}

int in_poly(P a, const Poly &p){
  int n = p.size(), c = 0;
  for(int i = 0; i < n; ++i){
    P s = p[i]-a, t = p[(i+1)%n]-a;
    if(!ccw(s,t,P(0,0))) return 1;
    if(s.Y > t.Y + EPS) swap(s,t);
    if((s.Y*t.Y < 0 or (s.Y*t.Y < EPS and t.Y > EPS)) and cross(s,t) < EPS) ++c;
  }
  if(c%2) return 2;
  return 0;
}

Poly convex_hull(Poly v){
  int n = v.size(), k = 0;
  sort(v.begin(),v.end(),cmp_y);
  Poly r(2*n);
  for(int i = 0; i < n; ++i){
    while(k > 1 and cross(r[k-1]-r[k-2],v[i]-r[k-2]) < -EPS) --k;
    r[k++] = v[i];
  }
  for(int i = n-2, t = k; i >= 0; --i){
    while(k > t and cross(r[k-1]-r[k-2],v[i]-r[k-2]) < -EPS) --k;
    r[k++] = v[i];
  }
  r.resize(k-1);
  return r;
}

W length(const Poly &p){
  W ret = 0;
  int n = p.size();
  for(int i = 0; i < n; ++i)
    ret += abs(p[i]-p[(i+1)%n]);
  return ret;
}

bool is_valid(const Poly &p, const vector<P> &q, int idx){
  for(const auto &e : q){
    if(not in_poly(e,p)) return false;
  }
  int n = p.size();
  idx += n-1;
  for(int k = 0; k < 2; ++k){
    int i = (idx+k)%n;
    for(int j = 0; j < n; ++j){
      if(i == j or (i+1)%n == j or (j+1)%n == i) continue;
      L l1(p[i],p[(i+1)%n]), l2(p[j],p[(j+1)%n]);
      if(is_cross(l2,l1)) return false;
    }
  }
  return true;
}

int main(){
  int n, k;
  while(cin >> n >> k, n){
    int const th = 1;
    Poly v;
    for(int i = 0; i < n; ++i){
      W x, y;
      cin >> x >> y;
      v.emplace_back(x,y);
    }
    Poly C = convex_hull(v);
    priority_queue<W> len;
    priority_queue<pair<W,Poly>> Q;
    W l = length(C);
    len.emplace(l);
    Q.emplace(l,C);
    set<Poly> appeared;
    while(Q.size()){
      Poly p = Q.top().second;
      l = Q.top().first;
      Q.pop();
      vector<P> I;
      for(int i = 0; i < n; ++i){
        bool f = true;
        for(auto e : p){
          if(abs(e-v[i]) < EPS){
            f = false;
            break;
          }
        }
        if(f) I.push_back(v[i]);
      }
      int m = p.size(), t = I.size();
      for(int i = 0; i < m; ++i){
        for(int j = 0; j < t; ++j){
          Poly p_ = p;
          p_.insert(p_.begin()+i+1, I[j]);
          if(not is_valid(p_,v,i+1)) continue;
          if(appeared.count(p_)) continue;
          if(len.size() >= k and len.top() < length(p_)) continue;
          Q.emplace(length(p_),p_);
          if(Q.size() > k*th) Q.pop();
          len.emplace(length(p_));
          if(len.size() > k*th) len.pop();
          appeared.insert(p_);
        }
      }
    }
    if(len.size() < k){
      cout << -1 << endl;
      continue;
    }
    // {
    //   W res = len.top();
    //   while (len.size()) {
    //     fprintf(stderr,"+ %.12f\n",len.top());
    //     len.pop();
    //     //if (len.size()) res = len.top();
    //   }
    //   printf("%.12f\n", res);
    // }
    printf("%.16f\n",len.top());
    // vector<W> res;
    // while (len.size()) {
    //   res.push_back(len.top());
    //   len.pop();
    // }
    // sort(res.begin(), res.end());
    // printf("%.12f\n", res[k-1]);
  }
}

