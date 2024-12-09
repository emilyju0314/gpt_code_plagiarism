#include<bits/stdc++.h> 
#include <algorithm> 
#define pb push_back 
#define ppb pop_back
#define mp make_pair 
#define INF 1e18+54
#define mod 1000000007
#define fi first
#define se second
#define rep(i,n) for (int i=0;i<n;i++)
#define loop(i,a,b) for (int i=a;i<b;i++)
#define rrep(i,e) for(int i=e; i>=0; i--)
#define rloop(i,s,e) for(int i=e; i>=s; i--)
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound


using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdd;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); 
} 
ll f(int a[],int n)
{
    int max_so_far=INT_MIN,max_ending=0,max_ending_abs=0,min_ending=0;

          for(int i=0;i<n;i++)
          {
            max_ending_abs=max({abs(min_ending+a[i]),abs(a[i]),abs(max_ending+a[i])});
            min_ending=min(a[i],min_ending+a[i]);
            max_ending=max(a[i],max_ending+a[i]);
            max_so_far=max(max_ending_abs,max_so_far);
          }
          return max_so_far;
}
int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(i%2==1)
                {
                    cout << i+1<<" ";
                }
                else
                {
                    cout << i-1<<" ";
                }
            }
        }
        else
        {

            for(int i=1;i<=n-3;i++)
            {
                if(i%2==1)
                {
                    cout << i+1<<" ";
                }
                else
                {
                    cout << i-1<<" ";
                }
            }
            cout << n<<" ";
            cout<<  n-2<<" ";
             cout<<  n-1<<" ";
        }
        cout <<endl;
      }

}






















    