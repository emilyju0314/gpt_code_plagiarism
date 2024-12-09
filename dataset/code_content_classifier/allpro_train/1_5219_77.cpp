#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define int long long
#define ll long long
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define mod 1000000007
#define F first
#define S second
#define printer(v) for(auto f: v) cout<<f<<" "
#define pb push_back
#define mp make_pair
#define all(c) c.begin(), c.end()
#define ipair pair<int,int>
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
 
int bin_power(int x, unsigned int y){   // Modular Exponentiation (Power in Modular Arithmetic)
    int temp;
    if( y == 0)
        return 1;
    temp = bin_power(x, y / 2);
    if (y % 2 == 0)
        return (temp * temp)%mod;
    else
        return (x * temp * temp)%mod;

    // ll res = 1; 
    // while(y){
    //     if(y & 1) res = (res * x)%mod; 
    //     y >>= 1; 
    //     x = (x * x)%mod;
    // }
    // return res;
}

int inverse_mod(int a){
    return bin_power(a, mod-2);
}

vector<bool> isPrime_Seive_Of_Erastothenes(long n){
    vector<bool> prime(n+1,true);
    prime[0] = prime[1] = false;
    for(long i=2;i*i<=n;i++){
        if(prime[i]){
            for(long j=i*i;j<=n;j+=i){
                prime[j] = false;
            }
        }
    }
    return prime;
}

bool is_integer(float k){
  return std::floor(k) == k;
}

int fact(int n);

int nCr(int n, int r) {
    if(r > n - r) r = n - r;
    int ans = 1;
    int i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

int fact(int n){
    int res = 1;
    for (int i = 2; i <= n; i++){
        res = res * i;
        res = res;
    }
    return res;
}

unsigned int gcd(unsigned int u, unsigned int v){       // Basic Euclidean Algorithm for GCD 
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}

int gcdExtended(int a, int b, int *x, int *y){      // Extended Euclidean Algorithm
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

int binarySearch(int l, int r, int k){
    if(l == r) return l;
    int mid = l + (r - l) / 2;
    cout<<'?'<<" "<<l+1<<" "<<mid+1<<"\n";
    cout.flush();
    int sum;
    cin>>sum;
    int x = mid - l + 1;
    if (x - sum >= k){
        return binarySearch(l, mid, k);
    }
    else{
        k -= (x - sum);
        return binarySearch(mid+1, r, k);
    }
}

bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}

int nextPrime(int N)
{
    if (N <= 1)
        return 2;
    int prime = N;
    bool found = false;
    while (!found) {
        prime++;
        if (isPrime(prime))
            found = true;
    }
    return prime;
}

signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> A(n);
        int ans = INT_MAX;
        int index = 0;
        for (int i = 0; i < n; ++i){
            cin>>A[i];
            if(A[i] < ans){
                ans = A[i];
                index = i;
            }
        }
        cout<<n - 1<<endl;
        for(int i = 0; i < index; i++){
            A[i] = ans + abs(index - i);
            cout<<i + 1<<" "<<index + 1<<" "<<A[i]<<" "<<ans<<endl;
        }
        for(int i = index + 1; i < n; i++){
            A[i] = ans + abs(index - i);
            cout<<i + 1<<" "<<index + 1<<" "<<A[i]<<" "<<ans<<endl;
        }
    }
    return 0;
}