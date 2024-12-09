#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int lst(int n){
    cout << "lst " << n << endl;
    int k;
    cin >> k;
    if (k == 0)
        return k;
    vector<int> V(k);
    copy_n(istream_iterator<int>(cin), k, V.begin());
    return k;
}

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++){
        auto k = lst(i);
        ans += k * (k - 1);
    }
    cout << "ans " << ans << endl;
}
