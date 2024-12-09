#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> min_predecessor(n), max_successor(n);
    min_predecessor[0] = arr[0];
    max_successor[n - 1] = arr[n - 1];

    for(int i = 1; i < n; i++) {
        min_predecessor[i] = min(min_predecessor[i - 1], arr[i]);
    }

    for(int i = n - 2; i >= 0; i--) {
        max_successor[i] = max(max_successor[i + 1], arr[i]);
    }

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        if(min_predecessor[x] < max_successor[y]) {
            cout << "Shi" << endl;
        } else {
            cout << "Fou" << endl;
        }
    }

    return 0;
}