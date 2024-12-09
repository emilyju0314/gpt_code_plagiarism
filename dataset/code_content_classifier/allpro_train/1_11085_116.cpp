#include <bits/stdc++.h>
using Int = int64_t;
using UInt = uint64_t;
using C = std::complex<double>;
#define rep(i, n) for(Int i = 0; i < (Int)(n); ++i)
#define rep2(i, l, r) for(Int i = (Int)(l); i < (Int)(r); ++i)
#define guard(x) if( not (x) ) continue;
#ifndef LOCAL_
#define fprintf if( false ) fprintf
#endif

template<typename T>
using RQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
   Int v, e, f;
   std::cin >> v >> e >> f;
   std::vector<Int> ss(e+1), ts(e+1), cs(e+1), fs(e+1), bs(e+1);
   rep2(i,1,e+1) {
      Int a, b, c, d;
      std::cin >> a >> b >> c >> d;
      ss[i] = a, ts[i] = b, cs[i] = d, fs[i] = 0, bs[i] = c;
   }
   std::vector<std::vector<Int>> es(v);
   rep2(i,1,e+1) {
       Int s = ss[i], t = ts[i];
      es[s].emplace_back(i);
      es[t].emplace_back(-i);
   }
   Int res = 0;
   Int source = 0, sink = v-1;
   std::vector<Int> hs(v);
   while( f > 0 ) {
      RQ<std::pair<Int,Int>> q;
      q.emplace(0, source);
      std::vector<Int> ps(v, -1), xs(v, -1), ys(v);
      xs[source] = 0;
      ys[source] = f;
      while( not q.empty() ) {
         Int d, s; std::tie(d, s) = q.top(); q.pop();
         guard( d == xs[s] );
         for(Int i : es[s]) {
            Int k = std::abs(i);
            Int t = i > 0 ? ts[k] : ss[k];
            Int tf = i > 0 ? bs[k] : fs[k];
            guard( tf > 0 );
            Int nd = d + (i>0?cs[k]:-cs[k]) + hs[s] - hs[t];
            guard( xs[t] == -1 or xs[t] > nd );
            xs[t] = nd;
            ps[t] = i;
            ys[t] = std::min(ys[s], tf);
            q.emplace(nd, t);
         }
      }
      Int tf = ys[sink];
      f -= tf;
      if( f > 0 and tf == 0 ) {
         res = -1;
         break;
      }
      rep(i, v) hs[i] += xs[i];
      for(Int i=sink, k=ps[i]; i!=source; i=(k>0?ss[k]:ts[-k]), k=ps[i]) {
         Int ak = std::abs(k);
         if( k > 0 ) {
            fs[ak] += tf;
            bs[ak] -= tf;
         }
         else {
            fs[ak] -= tf;
            bs[ak] += tf;
         }
      }
      res += tf * hs[sink];
      if( f == 0 ) break;
   }
   printf("%ld\n", res);
}

