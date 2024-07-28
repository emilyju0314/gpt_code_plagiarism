#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            pq.push(num);
        }

        int total_cost = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int sum = a + b;
            total_cost += sum;
            pq.push(sum);
        }

        cout << total_cost << endl;
    }

    return 0;
}
