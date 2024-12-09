            #include <bits/stdc++.h>
    
            using namespace std;
    
            typedef long long ll;
    
            typedef vector<long long> vl;
            #define PB push_back
            #define MP make_pair
    
            #define ln "\n"
    
            #define forn(i,e) for(ll i=0; i<e; i++)
            #define forsn(i,s,e) for(ll i=s; i<e; i++)
            #define rforn(i,e) for(ll i=e; i>=0; i--)
            #define rforsn(i,s,e) for(ll i=s; i>=e; i--)
            #define vasort(v) sort(v.begin(), v.end())
            #define vdsort(v) sort(v.begin(), v.end(),greater<ll>())
    
            #define out1(x1) cout << x1 << ln
            #define out2(x1,x2) cout << x1 << " " << x2 << ln
            #define out3(x1,x2,x3) cout << x1 << " " << x2 << " " << x3 << ln
            #define out4(x1,x2,x3,x4) cout << x1 << " " << x2 << " " << x3 << " " << x4 << ln
            #define out5(x1,x2,x3,x4,x5) cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << ln
            #define out6(x1,x2,x3,x4,x5,x6) cout << x1 << " " << x2 << " " << x3 << " " << x4 << " " << x5 << " " << x6 << ln
            
            #define in1(x1) cin >> x1
            #define in2(x1,x2) cin >> x1 >> x2
            #define in3(x1,x2,x3) cin >> x1 >> x2 >> x3
            #define in4(x1,x2,x3,x4) cin >> x1 >> x2 >> x3 >> x4
            #define in5(x1,x2,x3,x4,x5) cin >> x1 >> x2 >> x3 >> x4 >> x5
            #define in6(x1,x2,x3,x4,x5,x6) cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6
            
            #define arrin(a,n) forn(i,n) cin >> a[i];
            #define arrout(a,n) forn(i,n) {cout << a[i] << " ";} cout << ln;
            #define arrinit(a,n,e) forn(i,n) a[i]=e;
            ll gcd(ll x, ll y){
                if (y == 0)
                    return x;
                return gcd(y, x % y);
            }
            ll power(ll x,ll y,ll k){  ///////        (x^y) %k
                if(y==0){
                    return 1;
                }
                ll p=power(x,y/2,k);
                if(y%2==0){
                    return (p*p)%k;
                }
                else{
                    return (p*p*x)%k;
                }
            }
            

    
            
            // pair<ll,ll> arr[100006];          
            void solve(){
                ll n,x,t,ans;
                in3(n,x,t);
                ans=t/x;
                if(n<=ans){
                    ans=(n*(n-1))/2;
                }
                else{
                    ans=(ans*(2*n-ans-1))/2;

                }
                out1(ans);
            } //string s;
            int main() 
            {
                //out1("hwllp");
                ios_base::sync_with_stdio(false);
                cin.tie(NULL);
                ll t=1;
                cin>>t;
                //out1(t);
                while(t--){
                    solve();
                }
            return 0;
            }