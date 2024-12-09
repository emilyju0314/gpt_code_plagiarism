#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> primes(n);
    for (int i = 0; i < n; i++) {
        cin >> primes[i];
    }

    long long k;
    cin >> k;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    pq.push(1);

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans = pq.top();
        pq.pop();

        for (int j = 0; j < n; j++) {
            pq.push(ans * primes[j]);
            if (ans % primes[j] == 0) break;
        }
    }

    cout << ans << endl;

    return 0;
}