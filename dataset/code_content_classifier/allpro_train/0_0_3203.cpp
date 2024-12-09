#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<queue<int>> lists(n);

    for (int i = 0; i < q; i++) {
        int query, t, x, s;
        cin >> query;

        if (query == 0) {
            cin >> t >> x;
            lists[t].push(x);
        } else if (query == 1) {
            cin >> t;
            while (!lists[t].empty()) {
                cout << lists[t].front() << " ";
                lists[t].pop();
            }
            cout << endl;
        } else if (query == 2) {
            cin >> s >> t;
            while (!lists[s].empty()) {
                lists[t].push(lists[s].front());
                lists[s].pop();
            }
        }
    }

    return 0;
}