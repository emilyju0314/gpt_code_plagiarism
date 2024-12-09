#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<queue<int>> queues(n);

    for (int i = 0; i < q; i++) {
        int type, t, x;
        cin >> type >> t;

        if (type == 0) {
            cin >> x;
            queues[t].push(x);
        } else if (type == 1) {
            if (!queues[t].empty()) {
                cout << queues[t].front() << endl;
            }
        } else if (type == 2) {
            if (!queues[t].empty()) {
                queues[t].pop();
            }
        }
    }

    return 0;
}