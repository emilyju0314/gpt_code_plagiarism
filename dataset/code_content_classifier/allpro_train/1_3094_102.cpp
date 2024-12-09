#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using namespace std;

vector<ll> ans;

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];
    sort(rall(A));
    sort(rall(B));
    sort(rall(C));

    rep(i,X)rep(j,Y)rep(k,Z){
        if(i*j*k>K)break;
        ans.push_back(A[i]+B[j]+C[k]);
    }
    sort(rall(ans));
 
    rep(i, K) cout << ans[i] << endl;
}
