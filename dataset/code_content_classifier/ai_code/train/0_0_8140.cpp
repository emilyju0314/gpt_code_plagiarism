#include <iostream>
#include <vector>
using namespace std;

int countCombinations(vector<long long>& coins, int N, int K, long long L, long long R) {
    int ans = 0;
    for(int mask = 1; mask < (1 << N); mask++) {
        int cnt = 0;
        long long sum = 0;
        for(int i = 0; i < N; i++) {
            if(mask & (1 << i)) {
                cnt++;
                sum += coins[i];
            }
        }
        if(cnt == K && sum >= L && sum <= R) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int N, K;
    long long L, R;
    cin >> N >> K >> L >> R;

    vector<long long> coins(N);
    for(int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int ans = countCombinations(coins, N, K, L, R);
    cout << ans << endl;

    return 0;
}