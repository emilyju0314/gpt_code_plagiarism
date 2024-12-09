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

    int max_f = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == i+1) {
            max_f++;
        }
    }

    int num_moves = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != i+1) {
            num_moves++;
        }
    }

    cout << max(max_f, max_f + num_moves) << endl;

    return 0;
}