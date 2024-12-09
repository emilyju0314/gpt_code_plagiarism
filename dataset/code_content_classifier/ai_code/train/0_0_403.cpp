#include <iostream>
#include <queue>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < N; i++) {
        pq.push(X[i]);
    }
    
    long long ans = 0;
    for (int i = 0; i < N - 1; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        ans = (ans + (b - a) * (N - i - 1)) % MOD;
        pq.push((a + b) / 2);
    }
    
    cout << ans << endl;
    
    return 0;
}