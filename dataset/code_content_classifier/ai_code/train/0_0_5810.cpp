#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate difficulty of the initial sequence
    int difficulty = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            difficulty++;
        }
    }
    cout << difficulty << endl;

    return 0;
}