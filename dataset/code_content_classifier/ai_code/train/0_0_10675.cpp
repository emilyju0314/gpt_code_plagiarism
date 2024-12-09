#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }

        vector<int> reordered;

        for (int i = 0; i < n; i++) {
            reordered.push_back(w[i]);
        }

        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << reordered[i] << " ";
        }
        cout << endl;
    }

    return 0;
}