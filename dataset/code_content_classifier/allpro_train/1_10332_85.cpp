/*
    Author: mr_cruise/krishrustagi
    
    Rules:
    1. Work for satisfaction and not for hunger.
    2. Read the question carefully.
    3. Check for the corner cases.
*/

#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll; 
#define fori(i, n) for (ll(i) = 0; (i) < (n); (i)++) 
#define foria(i, a, b) for (ll(i) = (a); (i) <= (b); (i)++) 
#define foriar(i, a, b) for (ll(i) = (a); (i) >= (b); (i)--)  
#define debug(a, n) for (ll i = 0; i < n; i++) cerr << a[i] << " "; cerr << '\n';
#define ff first 
#define ss second 
#define pb push_back 
#define endl '\n'

const ll mod = 1e9 + 7;
const ll imx = INT_MAX;
const ll imn = INT_MIN;
 
int static dp[1001][1001];

void solve()
{
    int n;
    cin >> n;

    ll a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    long long temp = 0, sum = 0;

    foria(i, 2, n-1)
    {
        temp += a[i-2];
        sum -= (a[i]*(i-1));
        sum += temp;
    }

    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
 
    int t = 1;
    cin >> t;
    fori(_, t)
    {
        // cout << "Case #" << _ + 1 << ": ";
        solve();
    }
    return 0;
}
