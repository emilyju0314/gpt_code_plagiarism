#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> piles(n);
    for(int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    sort(piles.begin(), piles.end(), greater<long long>());

    int q;
    cin >> q;

    vector<int> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    long long total_sum = 0;
    long long current_sum = 0;
    int num_operations = 1;
    priority_queue<long long> pq;

    for(int i = 0; i < n; i++) {
        current_sum += piles[i];
        pq.push(piles[i]);
        if (num_operations < n) {
            total_sum += current_sum;
            num_operations++;
        }
    }

    for(int i = 0; i < q; i++) {
        long long result = total_sum;
        int remaining_operations = n - queries[i];
        result -= (n - 1) * (pq.top());
        result += (remaining_operations) * (pq.top());
        cout << result << " ";
    }

    return 0;
}