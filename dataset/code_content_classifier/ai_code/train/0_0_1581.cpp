#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> l(n);
        vector<int> unlocked;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> l[i];
            if (l[i] == 0) {
                unlocked.push_back(a[i]);
            }
        }

        sort(unlocked.begin(), unlocked.end());

        int index = 0;
        for (int i = 0; i < n; i++) {
            if (l[i] == 0) {
                a[i] = unlocked[index];
                index++;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}