#include<bits/stdc++.h>
#define ll long long int
#define lb lower_bound
#define pb push_back
#define m_p make_pair
#define F first
#define S second
#define fr(j,x,y) for(j=x;j<=y;j++)
//#define N 1000001
#define frn(i,x,y) for(i=x;i>=y;i--)
#define pll pair<ll,ll>
using namespace std;
 
ll __hcf(ll a,ll b){
	if(a==0)
		return b;
	return __hcf(b%a,a);
}
ll MOD = 1000000007;
ll pow(ll a,ll b){
	if(b==0){
		return 1;
	}
	ll k = b/2;
	ll c = pow(a,k);
	c = (c*c)%MOD;
	if(b%2==0)
		return c;
	else
		return (c*a)%MOD;
}

bitset<10000009> B;
vector<ll> seive(){
    
    vector<ll> v;
    for(ll  i=2;i<=10000009;i++){
        if(B[i]==0){
            v.pb(i);
            for(ll j=i*2;j<=10000009;j+=i)
            	B[j]=1;
        }
    }
    return v;
}

ll gcd(ll a, ll b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; 
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return 0;
    else
    {
        int res = (x % m + m) % m;
        return res;
    }
}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    //freopen("input.in","r",stdin); freopen("output.txt","w",stdout); 
    ll T=1;
    //cin>>T;    	
	for(int U=1;U<=T;U++){
		ll n=U;
		cin>>n;
		vector<ll> v,v2;
		for(int i=2;i<n;i++){
			ll c = modInverse(i,n);
			//cout<<i<<" "<<c<<endl;
			if(c!=0){
				if(c>i){
					v.pb(i);
					v.pb(c);
				}
				else if(c==i){
					v2.push_back(c);
				}
			}
		}
		if(v2.size()>=2){
			for(int i=0;i<v2.size();i++)
				v.pb(v2[i]);
			v.pb(1);
		}
		else{
			v.pb(1);
		}
		sort(v.begin(),v.end());
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		
		//cout<<"NO "<<U<<endl;
	}
}





