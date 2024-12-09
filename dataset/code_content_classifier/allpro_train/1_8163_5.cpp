/*Author-Nilesh Chandra(isocyanide7)*/
#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define dd double
#define pb push_back
#define ff first
#define ss second
#define Mp make_pair
const ll Mod=1000000007;
const ll INF=999999999999999999;
const ll NN=(ll)(1e6+5);
ll min(ll x,ll y){if(x<y) return x;return y;}
ll max(ll x,ll y){if(x>y) return x;return y;}
ll power(ll x,unsigned ll y) 
{ 
    if (y==0) 
        return 1; 
    else if (y%2==0) 
        return power(x,y/2)*power(x,y/2); 
    else
        return x*power(x,y/2)*power(x,y/2); 
}
ll hcf(ll a,ll b) 
{ 
    if(b==0) 
        return a; 
    return hcf(b,a%b);  
}
int main()
{
   fio;
   /*#ifndef ONLINE_JUDGE 
    	freopen("input.txt", "r", stdin); 
    	freopen("output.txt", "w", stdout); 
    	freopen("error.txt", "w", stderr); 
   #endif*/
   ll TT=1;
   cin>>TT;
   while(TT--)
   {
       ll i,n,sum=0,flag=0,j;
       cin>>n;
       vector <ll> v(4);
       for(auto &u:v)
        cin>>u,sum+=u,flag+=(u>n-2);
       if(sum==4*n || !flag)
       {
           cout<<"YES\n";
           continue;
       }  
       flag=0;
       vector <ll> a=v;
       for(i=0;i<16;i++)
       {
           bitset <4> bs(i);
           //cout<<i<<" ";
           for(auto &u:a)
            u=0;
           for(j=0;j<4;j++)
           {
               ll x=(4+j-1)%4;
               if(bs[j])
                a[j]++,a[x]++;
           }
           ll f=0;
        //    for(auto &u:a)
        //     cout<<u<<" ";
        //    for(auto &u:v)
        //     cout<<u<<" "; 
        //    cout<<"\n"; 
           for(j=0;j<4;j++)
            if(a[j]>v[j] || v[j]-a[j]>n-2)
            {
                f=1;
                break;
            }
            if(!f)
            {
                //cout<<i<<" ";
                flag=1;
                break;
            }
       } 
       cout<<(!flag?"NO":"YES")<<"\n";
   }
}