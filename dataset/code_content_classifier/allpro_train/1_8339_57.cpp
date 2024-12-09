
// Problem: C. Minimum Grid Path
// Contest: Codeforces - Educational Codeforces Round 106 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1499/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <bits/stdc++.h>
#define int long long int
#define fi(i, n) for( int i=0 ; i<n ; i++ )
#define fr(i, a, b) for( int i=a ; i<b ; i++ )
#define frd(i, a, b) for( int i=a ; i>=b ; i-- )
#define fd(i, n) for( int i=n-1; i>=0 ; i-- )
#define fi1(i, n) for( int i=1 ; i<n ; i++ )
#define fit(i,m) for(auto i=m.begin(); i!=m.end();i++)
#define fil(a,b) memset(a, b, sizeof(a));
#define fila(ar,n) int ar[n]; fi(i,n) cin>>ar[i];
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define ci(n) int n; cin>>n;
#define cis(s) string s; cin>>s;
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define endl cout<<"\n";
#define mp map<int,int>
#define mpv map<int,vi>
#define mpd map<int,int,greater<int>>
#define dec greater <int> 
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define mkp make_pair
#define vvi vector<vector<int>>
#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
typedef long long ll;
using namespace std;
int const mod = 1e9+7;
int INF=1000000000;
const int N =1e6+3;
const int M=1e5+5;
bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) {
  if(v1[1]==v2[1]) return v1[0] < v2[0];                             
 return v1[1] < v2[1]; //increasing order 
}  
bool comp(pair<int, int> p1, pair<int, int> p2){
if(p1.second == p2.second){
return p1.first < p2.first;
}
return p1.second < p2.second;
}
//log(min(a,b)) ->
int gcd(int a, int b)  
{  
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}  
int findGCD(int arr[], int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
} 
int lcm(int a, int b)  
{  
    return (a*b)/gcd(a, b);  
}
//-----------------------
//bitwise_operation ---------
//xth bit set or not
bool bit_setc(int n,int x) {  if ( n & ( 1LL<<x ) ) return true; return false; }
//set xth bit on
int bit_set(int n,int x) { return  n= n | (1LL<<x); }
//toggle xth bit 
int bit_tog(int n, int x) { return n = n ^ (1LL<<x); }
//bitwise_operation_end-------------
//--------------------------
//log(n) ->
int power(int a,int b){
      if(b==0) return 1;
      if(b==1) return a;
      if(b%2==0){
          return power(a,b/2)*power(a,b/2);            
      } 
      else return power(a,b/2)*power(a,b/2)*a;
} //(space - constant/ time- log(n)) ->
int power_bit(int a,int b,int m){
                int ans = 1;
while(b > 0){
    if(b %2 ){
        ans = (ans * a) %m;
    }
    a = (a * a)%m;
    b = b/2;
}
return ans;
} 
//(a*b) mod m --- a,b <=10^10 , mod<=10^15
int multiply_bit(int a,int b,int m){
                int ans = 1;
while(b > 0){
    if(b %2 ){
        ans = (ans + a) %m;
    }
    a = (a + a)%m;
    b = b/2;
}
return ans-1;
} /*
int f[M];
void fac(){  f[0]=1;
    for(int i=1;i<M;i++){
         f[i]=i*f[i-1];
         f[i]%=mod;
    }
} 
int nCn(int n,int i){
    int u=f[n];                 //upper_numerator
    int l=f[i]*f[n-i]; l=l%mod; //lower_denomiator
    l=power_bit(l,mod-2,mod);   //modulo_inverse
    return (u*l)%mod;
} /* 
*/
int x[]={-1,0,1,0};
int y[]={0,-1,0,1};
int32_t main()
{    ios::sync_with_stdio(0);
cin.tie(0);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif  
    cout << fixed << setprecision(10);
    int t=1;  
    cin>>t; 
    while(t--){ //fil(dp,-1)  
       ci(n) fila(a,n)
       int sum1=a[0],sum2=a[1],min1=a[0],min2=a[1];
       int ans=n*(a[0]+a[1]);
       fr(i,2,n){
       	  if(i%2){
       	  	 min2=min(min2,a[i]);
       	  	 sum2+=a[i];
       	  }
       	  else {
       	  	min1=min(min1,a[i]);
       	  	 sum2+=a[i];
       	  }
       	  ans=min({ans,sum2+min2*(n-(i+1)/2)+sum1+min1*(n-(i+2)/2)});
       }
       cout<<ans;
       endl
    } 
    return 0;
}