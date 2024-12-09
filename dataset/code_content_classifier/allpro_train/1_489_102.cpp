#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 3005;
const int MOD = 998244353;
ll N,S,A[MN],D[MN],ans;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N >> S;
    for(int i=1; i<=N; i++){
        cin >> A[i];
        D[0] = i;
        if(S>=A[i]) ans = (ans+D[S-A[i]]*(N-i+1))%MOD;
        for(int x=S; x>=0; x--){
            if(A[i]+x>S) continue;
            D[A[i]+x] = (D[A[i]+x]+D[x])%MOD;
        }
    }
    cout << ans;
}
