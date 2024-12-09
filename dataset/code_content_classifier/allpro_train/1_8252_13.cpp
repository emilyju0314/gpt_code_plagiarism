/*

#include "bits/stdc++.h"
//#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;


const ll mod = 1e9+7;
const ll mod2= 998244353;
//const ll n_mod= 4294967296;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);
//
inline ll MOD(ll x, ll m = mod){
    ll y = x % m; //
    return (y >= 0) ? y: y+m;
}


const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
#define pii pair<int,int>
#define vii vector<int>
#define pLL pair<ll,ll>
#define vLL vector<ll>

/// ===========================================  template  =======================================================



// struct cm
// {
//   bool operator () ( const node n1, const node n2  ) const{
// return n1.cost>n2.cost;
//   }
// };


void solve(){
    


}




int main()
{

    FASTIO
  
   
  // int t; cin>>t;  for(int i=1;i<=t;i++){ solve();    }

    




// end
}



*/




#include "bits/stdc++.h"
//#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;


const ll mod = 1e9+7;
const ll mod2= 998244353;
//const ll n_mod= 4294967296;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);
//
inline ll MOD(ll x, ll m = mod){
    ll y = x % m; //
    return (y >= 0) ? y: y+m;
}


const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
#define pii pair<int,int>
#define vii vector<int>
#define pLL pair<ll,ll>
#define vLL vector<ll>

/// ===========================================  template  =======================================================



// struct cm
// {
//   bool operator () ( const node n1, const node n2  ) const{
// return n1.cost>n2.cost;
//   }
// };



void solve(){
  

}

ll ax[]= {-1, 0 , 1, -0 };
ll ay[]= {0, -1, 0, 1 };


void bfs(ll x, ll y, vector<vLL>&d, vector<vLL>&a ){
    ll n= a.size(), m= a[0].size();
    queue<pLL>qu; d[x][y]=1; qu.push({x,y});

    while(qu.empty()==0){
        pLL u= qu.front(); qu.pop();
        ll i,j;
        for(i=0;i<4;i++){
            pLL v= { u.XX + ax[i], u.YY + ay[i] };
            ll tx= u.XX+ax[i], ty= u.YY+ay[i];
           
            if(tx>=0 and ty>=0 and tx<n and ty<m and d[v.XX ][v.YY]==0 and a[v.XX][v.YY]!=-1 ){
               // if(a[v.XX][v.YY ]==-1) d[u.XX + ax[i]][u.YY + ay[i]]=-1;
               // else
                d[u.XX + ax[i]][u.YY + ay[i]] = d[u.XX][u.YY] + 1;
                qu.push(v);
            }
        }
    }



}


int main()
{

FASTIO

/*   int t; //scanf("%d",&t);  
   cin>>t;
   for(int i=1;i<=t;i++){ //printf("Case #%d: ",i ); 
     solve();    } */

    ll n,m,w; cin>>n>>m>>w; ll i,j;
    vector < vLL > d1 (n, vLL(m) ); vector < vLL > d2 (n, vLL(m) ); vector < vLL > a(n, vLL(m) );

    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cin>>a[i][j];
    }
/*    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
*/
//cout<<1<<endl;
    bfs(0,0, d1, a); bfs(n-1, m-1, d2, a);

    ll best_suru= 1e18;


    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]>=1 and d1[i][j]!=0){
                best_suru= min( best_suru, w*(d1[i][j]-1) + a[i][j]  );
            }
        }
    }
 //cout<<best_suru<<" ++\n";

    ll ans= (d1[n-1][m-1]-1)*w;
    if(d1[n-1][m-1]==0) ans= 1e18;
//cout<<ans<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]>=1 and d2[i][j]!=0 and best_suru!=1e18){
                ans= min(ans, best_suru + w*(d2[i][j]-1) + a[i][j] );
            }
        }
    }


    if(ans==1e18) ans=-1;
    cout<<ans<<endl;

 	



// end
}









/*

#include "bits/stdc++.h"
//#include<stdio.h>
#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
using namespace std;)

typedef long long int ll;#define WRITE(f) freopen(f, "w", stdout)

typedef unsigned long long int ull;
typedef long double ld;


const ll mod = 1e9+7;
const ll mod2= 998244353;
//const ll n_mod= 4294967296;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

// #define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
// #define hoise cerr<<"hoise - "<<__LINE__<<"\n"
// #define tham getchar()
// mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);
//
inline ll MOD(ll x, ll m = mod){
    ll y = x % m; //
    return (y >= 0) ? y: y+m;
}


const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
#define pii pair<int,int>
#define vii vector<int>
#define pLL pair<ll,ll>
#define vLL vector<ll>

/// ===========================================  template  =======================================================



// struct cm
// {
//   bool operator () ( const node n1, const node n2  ) const{
// return n1.cost>n2.cost;
//   }
// };


void solve(){
    


}




int main()
{

    FASTIO
  
   
  // int t; cin>>t;  for(int i=1;i<=t;i++){ solve();    }

    




// end
}



*/