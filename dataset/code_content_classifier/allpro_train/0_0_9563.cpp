#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> order;
    order.push_back(0);
    vector<bool> visited(n, false);
    visited[0] = true;
    int curr = 0;

    while (order.size() < n) {
        int next1 = (2 * curr) % n;
        int next2 = (2 * curr + 1) % n;

        if (!visited[next1]) {
            order.push_back(next1);
            visited[next1] = true;
            curr = next1;
        } else if (!visited[next2]) {
            order.push_back(next2);
            visited[next2] = true;
            curr = next2;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << order[i] << " ";
    }
    cout << endl;
    
    return 0;
}