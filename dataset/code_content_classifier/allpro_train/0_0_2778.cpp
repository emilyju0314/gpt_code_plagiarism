#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        bool reachable = false;
        for (int j = x; j < y; j++) {
            if ((array[j] & array[j+1]) > 0) {
                reachable = true;
                break;
            }
        }

        if (reachable) {
            cout << "Shi" << endl;
        } else {
            cout << "Fou" << endl;
        }
    }

    return 0;
}