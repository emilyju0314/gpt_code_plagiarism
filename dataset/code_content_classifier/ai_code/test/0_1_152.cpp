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

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> a(n, 0);
        bool possible = true;

        for (int i = 0; i < n; i++) {
            if (p[i] > i + 1) {
                a[i] = p[i];
            } else if (p[i] < i + 1) {
                a[i] = -p[i];
            } else {
                possible = false;
                break;
            }
        }

        if(!possible){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}