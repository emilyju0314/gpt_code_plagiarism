#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n-1);
    vector<int> b(n-1);

    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    vector<int> t(n);

    bool possible = true;

    for (int i = 0; i < 4; i++) {
        t[0] = i;
        bool valid = true;

        for (int j = 1; j < n; j++) {
            t[j] = (a[j-1] | t[j-1]);

            if ((t[j-1] & t[j]) != b[j-1]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << t[i] << " ";
        }
    } else {
        cout << "NO";
    }

    return 0;
}