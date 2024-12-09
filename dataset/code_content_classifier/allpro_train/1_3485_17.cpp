#ifdef Prateek
  #include "\Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back 
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;
const int n = 4;

int ans;

void solve(vector <int> &X, vector <int> &Y) {
   vector<int> x, y;
   for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
         for (int k = 0; k < n; ++k) {
            {
               x = {X[i], X[i], X[j], X[j]};
               y = {Y[k], Y[k] + abs(X[i] - X[j]), Y[k], Y[k] + abs(X[i] - X[j])};
               vector<int> perm = {0, 1, 2, 3};
               do {
                  int res = 0;
                  for (int i = 0; i < 4; ++i) {
                     res += abs(X[i] - x[perm[i]]) + abs(Y[i] - y[perm[i]]);
                  }
                  ans = min(ans, res);
               } while (next_permutation(all(perm)));
            }
            {
               x = {X[i], X[i], X[j], X[j]};
               y = {Y[k], Y[k] - abs(X[i] - X[j]), Y[k], Y[k] - abs(X[i] - X[j])};
               vector<int> perm = {0, 1, 2, 3};
               do {
                  int res = 0;
                  for (int i = 0; i < 4; ++i) {
                     res += abs(X[i] - x[perm[i]]) + abs(Y[i] - y[perm[i]]);
                  }
                  ans = min(ans, res);
               } while (next_permutation(all(perm)));  
            }
         }
      }
   }
}

void test(){
   vector <int> X(n), Y(n);
   for (int i = 0; i < n; ++i) {
      cin >> X[i] >> Y[i];
   } 
   ans = 1e18;
   solve(X,Y);
   solve(Y,X);
   cout << ans << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
