#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<pair<int, int>> BC(M);
    for(int i = 0; i < M; i++) {
        cin >> BC[i].second >> BC[i].first;
    }
    
    sort(BC.rbegin(), BC.rend());
    
    int idx = 0;
    long long ans = 0;
    
    for(int i = 0; i < N; i++) {
        if(idx < M && BC[idx].first > A[i]) {
            ans += BC[idx].first;
            BC[idx].second--;
            if(BC[idx].second == 0) {
                idx++;
            }
        } else {
            ans += A[i];
        }
    }
    
    cout << ans << endl;
    
    return 0;
}