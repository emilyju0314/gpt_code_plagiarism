#include<bits/stdc++.h>
using namespace std;
#define mp make_pair 
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

typedef long long ll;
typedef unsigned long long ull;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int nMax = 1e6+5;
const ll mod = 1e9+7;

int t,n;
ll arr[200005],sum;

ll binser(ll x) {
    ll ans = -1, l = 0, r = n-1;
    while(l <= r) {
        ll mid = (l+r)/2;
        if (arr[mid] >= x) {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return ans;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
    while(t--) {
        cin >> n;
        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        sort(arr,arr+n);
        sum = 0;
        for (int i=0;i<n;i++) {
            ll cnt = binser(arr[i]-2);
            cnt = i-cnt;
            if (cnt >= 2) {
                sum += ((cnt-1)*cnt / 2);
            }
        }
        cout << sum << "\n";
    }
	return 0;
}