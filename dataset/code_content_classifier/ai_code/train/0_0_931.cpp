#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long ans = 0;
    map<int, long long> dp;
    for(int j = 0, k = 0; j < N; j++) {
        while(k < N && dp[A[k]] < L) {
            dp[A[k]]++;
            k++;
        }

        ans += k - j;

        if(k == j) {
            k++;
        } else {
            dp[A[j]]--;
        }
    }

    cout << ans << endl;

    return 0;
}