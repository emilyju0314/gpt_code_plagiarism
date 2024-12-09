#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,j,n) for(ll i=j;i<n;i++)
const int mod = 1e9+7;
ll gcd(ll a,ll b){ return a?gcd(b%a,a):b; }
ll power(ll a, ll b, ll m=mod){
    if(a==0 || b==1) return a;
    if(b==0) return 1;
    ll ans=1;
    while(b>=1){ if(b&1){b--;ans = (ans*a) % m;}a = (a*a)% m;b = b>>1;}
    return ans;
}
ll inv(ll a,ll m){
    return power(a,m-2,m);
}

int LCSubStr(string X, string Y, int m, int n)
{
    // Create a table to store
    // lengths of longest
    // common suffixes of substrings.  
    // Note that LCSuff[i][j] contains
    // length of longest common suffix
    // of X[0..i-1] and Y[0..j-1].
 
    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
                    // longest common substring
 
    /* Following steps build LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            // The first row and first column
            // entries have no logical meaning,
            // they are used only for simplicity
            // of program
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}
 

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    ll t=1;
    cin>>t;
    string a,b;
    while(t--)
    {
        cin>>a>>b;
        int x = a.length();
        int y = b.length();
        int xx =  LCSubStr(a,b,x,y);
        ll ans = x + y -2*xx;
        cout<<ans<<"\n";
    }
    return 0;
}
