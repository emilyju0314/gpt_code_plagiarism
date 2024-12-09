#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t, k;
    cin >> n >> t >> k;

    vector<int> a(t);
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }

    if (k == 1) {
        if (t > 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    int curr = 2;
    int currLeaf = 2 + a[0];
    cout << n << endl;
    cout << "1 " << curr << endl;
    for (int i = 0; i < t; i++) {
        int group = i + 2;
        int nextGroup = i + 3;
        for (int j = 0; j < a[i]; j++) {
            if (j == 0) {
                cout << curr << " 1" << endl;
            } else {
                cout << curr << " " << currLeaf << endl;
                currLeaf++;
            }
        }
        curr = currLeaf;
    }
    for (int i = 0; i < n - curr + 1; i++) {
        cout << "1 " << curr << endl;
        curr++;
    }

    return 0;
}