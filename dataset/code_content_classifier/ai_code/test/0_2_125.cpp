#include <iostream>
#include <vector>
#include <algorithm>

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
            if (a[i - 1] != current) {
                a[i] = current;
                current++;
            } else {
                a[i] = current;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}