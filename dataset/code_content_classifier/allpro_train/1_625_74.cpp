#include<bits/stdc++.h>
#define io_o() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fst first
#define scd second
#define endl "\n"
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define REP(i,n) for(int i = 0; i < n; i++)
#define print1d(a) for(auto v: a) cout << v << " "; cout << endl;
#define int ll

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int32_t main(){
    io_o(); 
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> h(n);

        for(int i = 0; i < n; i++){
            cin >> h[i];
        }


        for(int i = 0; i < k; i++){
            int j, flag = 1;
            for(j = 0; j < n - 1; j++){
                if(h[j] < h[j + 1]){
                    h[j] ++;
                    flag = 0;
                    break;
                }
            }
            if(flag){
                cout << -1 << endl;
                break;
            }
            if(i == k - 1) {
                cout << j + 1 << endl;
                break;
            }
        }
        
    }
    return 0;
}

