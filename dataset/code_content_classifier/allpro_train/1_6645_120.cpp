#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, X[100000];
    cin >> N >> M;
    for(int i=0; i<M; i++) cin >> X[i];
    sort(X, X+M);

    vector<int> diff;
    for(int i=0; i<M-1; i++) diff.push_back(X[i+1] - X[i]);
    sort(diff.begin(), diff.end());

    int64_t ans = 0;
    for(int i=0; i<M-N; i++) ans += diff[i];
    cout << ans << endl;
    return 0;
}