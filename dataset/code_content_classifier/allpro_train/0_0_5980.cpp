#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int operations = 0;
    int empty = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            empty++;
        } else if (b[i] == i + 1) {
            b[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            if (a[i] <= n - empty) {
                if (b[a[i] - 1] == 0) {
                    b[a[i] - 1] = a[i];
                    a[i] = 0;
                    empty--;
                    operations++;
                }
            }
        }
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] != 0) {
            while (b[i] != i + 1) {
                if (b[i] == 0) {
                    while (a[j] == 0) {
                        j++;
                    }
                    if (a[j] != i + 1) {
                        operations++;
                    }
                    b[i] = a[j];
                    a[j] = 0;
                    j++;
                } else {
                    operations++;
                    a[j] = b[i];
                    b[i] = 0;
                    j++;
                }
            }
        }
    }

    cout << operations << endl;

    return 0;
}