#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> reliabilities(n);
    for (int i = 0; i < n; i++) {
        cin >> reliabilities[i];
    }

    priority_queue<int> pq;
    long long total_reliability = 0;

    for (int i = 0; i < k; i++) {
        int max_reliability = 0;
        for (int j = 0; j < n; j++) {
            if (pq.size() < k) {
                pq.push(reliabilities[j]);
                total_reliability += reliabilities[j];
            } else {
                max_reliability = max(max_reliability, reliabilities[j]);
            }
        }
        if (!pq.empty()) {
            total_reliability -= max_reliability;
            pq.pop();
            pq.push(max_reliability);
        }
    }

    cout << total_reliability << endl;

    return 0;
}