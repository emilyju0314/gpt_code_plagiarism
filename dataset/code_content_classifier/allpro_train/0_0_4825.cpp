#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> power(N);
    for (int i = 0; i < N; i++) {
        cin >> power[i];
    }
    
    sort(power.begin(), power.end());
    
    vector<long long> prefix_sum(N+1);
    for (int i = 1; i <= N; i++) {
        prefix_sum[i] = prefix_sum[i-1] + power[i-1];
    }
    
    long long ans = 0;
    for (int i = 0; i < M; i++) {
        int left_index = i;
        int right_index = M - i - 1;
        ans = max(ans, prefix_sum[left_index] + prefix_sum[N] - prefix_sum[N - right_index]);
    }
    
    cout << ans << endl;
    
    return 0;
}