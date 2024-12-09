#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 998244353;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<int> cnt(N+1, 0);
    for(int i = 0; i < N; i++) {
        cnt[A[i]]++;
    }
    
    if(cnt[1] == 0 || cnt[A[0]] > 1) {
        cout << 0 << endl;
        return 0;
    }
    
    long long ans = 1;
    int prev = 1;
    for(int i = 1; i < N; i++) {
        if(cnt[A[i]] == 0) {
            cout << 0 << endl;
            return 0;
        }
        
        if(A[i] != prev && cnt[A[i]] == 1) {
            ans = (ans * cnt[A[i]]) % mod;
        }
        
        cnt[A[i]]--;
        prev = A[i];
    }
    
    cout << ans << endl;
    
    return 0;
}