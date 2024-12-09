#include <bits/stdc++.h>
typedef long long int ll;
#define in(v,n) for(int i = 0 ; i < n ; i++) cin >> v[i];
#define f(i,a,b) for(int i = a ; i < b ; i++)
#define frev(a,b) for(int i = a ; i >= b ; i--)
#define mod 1000000007
using namespace std;
#define pb push_back
#define debugVector(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;
#define debugArray(arr, n) for(int i=1; i<n; i++) cout << arr[i] << " "; cout << endl;
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
typedef vector<int> vi;
typedef pair<int, int> pi;
#define o1(x) cout<<x<<'\n'
#define o2(x,y) cout<<x<<" "<<y<<"\n";
#define o3(x,y,z) cout<<x<<" "<<y<<" "<<z<<'\n'
#define nl cout <<"\n"
#define s(v) sort(v.begin(), v.end());
#define imax INT_MAX
#define imin INT_MIN
//A....Z 65....90
//a....z 97....122

int main(int argc, char **argv)
{
	// Code goes here
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		while (n and n % 2 == 0) {
			n /= 2;
		}

		if (n == 1) {
			o1("NO");
		} else {
			o1("YES");
		}

	}
}
