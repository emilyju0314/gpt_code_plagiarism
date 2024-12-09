/*Be patient && calm!
All our dreams can come true, if we have the courage to pursue them.
I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced one kick 10,000 times.
Do not pray for an easy life, pray for the strength to endure a difficult one.
When something is important enough, you do it even if the odds are not in your favor.
First, solve the problem. Then, write the code.
Fix the cause, not the symptom.
Simplicity is the soul of efficiency.
Make it work, make it right, make it fast.
No matter how hard it gets, NEVER GIVE UP*/
// set<string>::iterator it;
//set<int>::reverse_iterator it;
#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pi;
ll powermd(ll n,ll k,int p){
	if(k==0)
		return 1;
	ll res=powermd(n,k/2,p);
	res=res*res%p;
	if(k&1)
		res=res*n%p;
	return res;
}
int fact(int n);
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int mod(ll a, ll b) {
  return (((a % b) + b) % b);
}
bool isP(int n){
	int a=sqrt(n);
	if(a*a==n)
		return true;
	return false;
}

//subsetSum
bool sSum(int sum,int a[],int n){
	bool subset[n+1][sum+1];
	for(int i=0;i<=n;i++)
		subset[i][0]=true;
	for(int i=1;i<=sum;i++)
		subset[0][i]=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j>=a[i-1])
				subset[i][j]=subset[i-1][j]||subset[i-1][j-a[i-1]];
			else
				subset[i][j]=subset[i-1][j];
		}
	}
	return subset[n][sum];
}
//subset sum problem

vector<int> prime;
vector<int> sumPrime;
void sieve(int n)
{
	// Create a boolean array
	// "prime[0..n]" and initialize
	// all entries it as true.
	// A value in prime[i] will
	// finally be false if i is
	// Not a prime, else true.
    int cnt=0;
	bool prim[n + 1];
	memset(prim, true, sizeof(prim));

	for (int p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed,
		// then it is a prime
		if (prim[p] == true)
		{
			// Update all multiples
			// of p greater than or
			// equal to the square of it
			// numbers which are multiple
			// of p and are less than p^2
			// are already been marked.
			for (int i = p * p; i <= n; i += p)
				prim[i] = false;
		}
	}

	// Print all prime numbers
	for (int p = 2; p <= n; p++)
		if (prim[p]){
			cnt++;
			prime.push_back(p);
		}
  	// cout<<cnt<<"\n";
}

void fill2(vector<vector<char>> &v){
	int m=v.size(),n=v[0].size();
	for(int i=0;i<m;i++){
		if(i%2==0){
			v[i][0]='R';
		}
		else
			v[i][0]='W';
		for(int j=1;j<n;j++){
			if(v[i][j-1]=='W')
				v[i][j]='R';
			else
				v[i][j]='W';
		}
	}
}
void fill1(vector<vector<char>> &v){
	int m=v.size(),n=v[0].size();
	for(int i=0;i<m;i++){
		if(i%2==0){
			v[i][0]='W';
		}
		else
			v[i][0]='R';
		for(int j=1;j<n;j++){
			if(v[i][j-1]=='W')
				v[i][j]='R';
			else
				v[i][j]='W';
		}
	}
}
bool check(vector<vector<char>> &v0,vector<vector<char>> &v){
	int m=v.size(),n=v[0].size();
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(v[i][j]!='.'){
				if(v[i][j]!=v0[i][j])
					return false;
			}
		}
	}
	return true;
}
void print(vector<vector<char>> &v){
	for(auto a:v){
		for (auto b:a){
			cout<<b;
		}
		cout<<"\n";
	}
}
void solve(){
	int m,n;
	cin>>m>>n;
	vector<vector<char>> v(m,vector<char>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>v[i][j];
		}
	}
	vector<vector<char>> v0(m,vector<char>(n)),v1(m,vector<char>(n));
	fill1(v0);
	if(check(v0,v)){
		cout<<"YES\n";
		print(v0);
		return;
	}
	fill2(v1);
	if(check(v1,v)){
		cout<<"YES\n";
		print(v1);
		return;
	}
	cout<<"NO\n";
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(NULL);
	int t;
	cin>>t;
	// t=1;
	while(t--){
		solve();
	}
	// cout<<powermd(51,59,247)<<"\n";
	// cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
	return 0;
}