#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << '[' << #x << " is: " << x << "] " << endl;
#define imod(a , n) (a % n + n ) % n

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define inF freopen("file.txt","r",stdin );
#define outF freopen("perimeter.out" , "w" , stdout ) ;
#define sor(v) sort(v.begin() , v.end());
#define print(v) for(auto f : v ) cout << f << " " ;
#define rsor(v) sort(v.rbegin() , v.rend());
#define rev(v) reverse(v.begin() , v.end());
#define int ll
#define ll long long
//#define int ll
#define pii pair<int , int >
const int N = 5e3 + 5 , M = N * 4 ;
const ll MOD = 1e9 + 7 , oo = 1e9 , OO = 1e18 ;

//37


int di[] = {1 , -1 , 0 , 0};
int dj[] = {0 , 0 , 1 , -1};



int32_t main()
{   //  inF;
    // inF;outF;
    fastio;
    // Dont Forget memset
  int t ;
  cin >> t ;


  while(t--){
     int n , nn;
     cin >> n ;
     nn = n ;
     map<int , int > mp ;

     vector<int>v ;
     int mx = 0 , ans = -1;


     for(int i = 2 ; i * i <= n; i += ( i == 2 ? 1 : 2)){
        while(n % i == 0){
            n /= i ;
            v.push_back(i);
            mp[i]++;
            if(mp[i] > mx)mx = mp[i] , ans = i ;
        }
     }
     if(n){
        if(mx == 0)mx = 1 , ans = n ;

     }
     cout << mx << '\n';

     for(int i = 1 ; i < mx ; i ++){
        cout << ans << " " ;
        nn /= ans ;
     }

     cout << nn ;




    cout << '\n';
  }
}
