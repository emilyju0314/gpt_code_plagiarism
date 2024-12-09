#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1e14;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;

signed main() {
    ll N;
    cin >> N;
    ll A, B;
    cin >> A >> B;
    N = N % 12;
    for(int i = 0;i < N;i++) {
        if(i % 2 == 0) {
            A = A - B;
        }
        else {
            B = A + B;
        }
    }
    cout << A << " " << B << endl;
}
