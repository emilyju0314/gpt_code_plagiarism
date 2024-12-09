#include<bits/stdc++.h> 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define f(x, m) for(auto x : m)
#define cpu() ios::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int ,int>>
#define vll vector<pair<ll ,ll>>
#define all(v) v.begin(),v.end()
#define sor(a) sort( a.begin(), a.end() )
#define ros(a) sort( a.rbegin(), a.rend())
#define prec(n) fixed << setprecision(n)
#define ff first
#define ss second
#define print(x) for(auto it : x) cout << it << " ";
#define debug(x) cerr << #x << " is " << x << endl;

typedef long long ll;
using namespace std;
// using namespace __gnu_pbds;
#define dbg(args...){ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> ) {cout << "NEXT\n"; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cerr << *it << " = " << a << ", ";
err(++it, args...);
}
template<typename... T>
void rd(T& ... args){
   (( cin >> args), ...);
}
template<typename... T>
void ps(T ... args){
   ((cout << args << ' '), ...);
   cout << '\n';
}
//  mp.max_load_factor(0.25); 
// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;
const int MOD = 1e9 + 7, MOD1 = 998244353LL, MAX = 1e5 + 5;
const char nl = '\n';      
const int INF = 1e9 + 5; 
int n, W; 
int w[MAX];
void solve(){
   cin >> n >> W; 
   vector<int> sob(n);
   for(int i = 0; i < n; i++){
      cin >> w[i];
   }
   w[n] = 0;
   sort(w, w + n);
   int id = 0;
   set<pair<int, int>> s;
   for(int i = n - 1; i >= 0; i--){
      auto xd = s.lower_bound({w[i], -1});
      if(xd == s.end()){
         id++;
         s.insert({W - w[i], id});
      }
      else{
         pii re = (*xd); 
         s.erase(xd);
         s.insert({re.ff - w[i], re.ss});
      }
   }
   cout << id << "\n";
}
int main(){
   cpu();
   int __ = 1;
   cin >> __;
   while(__--){
      solve();
   }
   return 0;
}