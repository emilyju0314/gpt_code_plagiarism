#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> queue;
    for (int i = 1; i <= n; i++) {
        queue.push_back(i);
    }

    int next = 0;
    for (int i = 0; i < min(k, (long long)n * 100); i++) {
        a[queue[next] - 1]--;
        if (a[queue[next] - 1] == 0) {
            queue.erase(queue.begin() + next);
        } else {
            next = (next + 1) % queue.size();
        }
    }

    if (queue.empty()) {
        cout << "-1" << endl;
    } else {
        for (int i = 0; i < queue.size(); i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    return 0;
}