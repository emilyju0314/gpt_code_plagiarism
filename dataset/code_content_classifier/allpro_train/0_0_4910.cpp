#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<int> remainder(K, 0);
    remainder[0] = 1;
    
    long long ans = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum = (sum + A[i]) % K;
        ans += remainder[sum];
        remainder[sum]++;
    }
    
    cout << ans << endl;
    
    return 0;
}