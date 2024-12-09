#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        vector<int> arr(t);
        for (int j = 0; j < t; j++) {
            cin >> arr[j];
        }

        int sum = 0;
        for (int j = 1; j < t; j++) {
            sum += arr[j];
            pq.push(sum);
        }

        if (t > 1) {
            pq.push(arr[0]);
        }
    }

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;

    return 0;
}