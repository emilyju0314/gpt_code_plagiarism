#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define tp(a,n) for(ll i=0;i<n;i++) cin>>a[i]
#define f(i,x,n) for(ll i=x;i<n;i++)
#define fr(i,x,n) for(ll i=n-1;i>=x;i--)
#define pb push_back
#define vl vector<ll>
#define mi map<int,int>
#define mp make_pair
#define all(a) a.begin(),a.end()
#define MAX 1000000
  
bool prime[MAX + 1];
  
int rb(string s)
{
    ll n=s.size(),k;
    f(i,0,n)
    {
        if(s[i]=='.'&&s[i+1]=='*')
           {
               k=i+1;
           }
    }
    return k;
}

int main(){
    //     #ifndef ONLINE_JUDGE
    //     freopen("./input.txt", "r", stdin);
    //     freopen("./output.txt", "w", stdout);
 
    // #endif
     
     
       
       ll t,a,b;
          //SieveOfEratosthenes();
       cin>>t;

    while(t--){
        ll n,x;
        cin>>n>>x;
        if(x==1)
        cout<<"NO\n";
        else
        {cout<<"YES\n";
        cout<<n*x<<" "<<n*(x-1)<<" "<<n*((2*x)-1)<<endl;
        }
}
     

         
    
}