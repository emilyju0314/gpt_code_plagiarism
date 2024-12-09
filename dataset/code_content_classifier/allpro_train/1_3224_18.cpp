#include <bits/stdc++.h>
#include <time.h>
using namespace std;

#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define all(x) x.begin(),x.end()
#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define MOD 1000000007
#define INF LONG_LONG_MAX
#define NINF LONG_LONG_MIN
//#define endl "\n"
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define db4(x,y,z,k) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\t"<<#z<<" : "<<z<<"\t"<<#k<<" : "<<k<<endl;

int main()
{
    IOS;
    ll t,k,n,m,d,u,v;
    t=1;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        ll l=1,r=n;
        while(l<r)
        {
            ll mid1=(l+r)/2;
            ll mid2=mid1+1;
            cout << "? " << mid1 << endl;
            cin >> u;
            cout << "? " << mid2 << endl;
            cin >> v;
            if(u<v)
            {
                r = mid1;
            }
            else
            {
                l = mid2;
            }
        }
        cout << "! " << l << endl;
    }
    return 0;
}
