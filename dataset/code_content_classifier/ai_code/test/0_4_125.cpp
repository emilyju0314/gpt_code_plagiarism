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

    int current = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (i > 0 && a[i-1] == current) {
                current++;
            }
            a[i] = current;
        } else {
            if (i > 0 && a[i-1] == a[i]) {
                current++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}