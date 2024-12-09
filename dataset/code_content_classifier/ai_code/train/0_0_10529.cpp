#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int additional_walks = 0;
    for (int i = 0; i < n - 1; i++) {
        int total_walks_needed = k - (a[i] + a[i + 1]);
        if (total_walks_needed > 0) {
            a[i + 1] += total_walks_needed;
            additional_walks += total_walks_needed;
        }
    }

    cout << additional_walks << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}