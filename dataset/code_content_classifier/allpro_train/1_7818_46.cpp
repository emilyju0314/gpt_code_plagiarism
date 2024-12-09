/*
*@author : Ujjawal Gupta 
*/
#include<bits/stdc++.h>
#define I int
#define ll long long 
#define ull unsigned long long 
#define S string 
#define V(i) vector<i> 
#define M(i,j) map<i,j>
#define P(i,j) pair<i,j>
#define li long 
#define ui unsigned int
#define D double
#define F float
#define C char
#define L size()
#define B bool
#define ff first
#define ss second
#define Q(n) queue <n>
#define ST(n) stack <n>
#define R return
#define FAST ios_base::sync_with_stdio(false);
#define FAST_INPUT cin.tie(0);
#define FAST_OUTPUT cout.tie(0);
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ppf pop_front()
#define ppb pop_back()
#define mp(n,m) make_pair(n,m)
#define ts(n) to_string(n)
#define loop(var1,start,end) for(var1=start;var1!=end;var1++)
#define lop(var1,start,end,it) for(var1=start;var1!=end;var1+=it)
#define rloop(var2,start,end) for(var2=start;var2!=end;var2--)
#define odd(n) (n&1)
#define nl "\n"
#define Mod 1000000007
#define PI 3.141592653589793238462
using namespace std;
//Function To fill the Values in vector.
void input(V(ll) &vec,ll n){
    ll temp,i;
    loop(i,0,n){
        cin>>temp;
        vec.pb(temp);
    }
}
//Check whether the no. is prime or not.
B isprime(ll n){
    ll i;
    if(n<=1) R false;
    if(n==2) R true;
    if(!odd(n)) R false;
    for(i=3;i*i<=n;i+=2)
        if(n%i==0) R false;
    R true;
}
//Overload Comparator Function.
B cmp(P(ll,ll) a,P(ll,ll) b){
    R a.first>b.first;
}
//Function to Conert Decimal no. to binary no.
S binary(ll n){
    S temp;
    if(n==0) R "0";
    while(n){
        temp+=ts(n%2);
        n/=2;
    }
    //reverse(temp.begin(),temp.end());
    R temp;
}
//Execution of function to count no. of digits.
ll countdigits(ll n){
    ll i,ans=0;
    i=n;
    while(i){
        ans++;
        i/=10;
    }
    R ans;
}
//unction to find n^k
ll power(ll n,ll k){
    ll i,ans=1;
    loop(i,0,k){
        ans*=n;
        ans=ans%Mod;
    }
    R ans;
}
//Execution of logical function.
S logical_function(){
    ll n,sum=0,count=0,i,j;
    cin>>n;
    V(ll) vec;
    input(vec,n);
    priority_queue<ll,V(ll),greater<ll>> q;
    loop(i,0,n){
        if(sum+vec[i]>=0){
            sum+=vec[i];
            count++;
            q.push(vec[i]);
        }
        else{
            if(!q.empty() && q.top()<vec[i]){
                sum+=abs(q.top()-vec[i]);
                q.pop();
                q.push(vec[i]);
            }
        }
    }
    R ts(count);
}
//Execution of Main Function.
I main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    FAST FAST_INPUT FAST_OUTPUT //For fast i/o console.
    ll t=1;
    //cin>>t;
    while(t--){
        //logical_function();
        cout<<logical_function();
        cout<<nl;
        //cout<<answer.
    }
}