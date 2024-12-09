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

    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] <= a[i]) {
                count++;
            }
        }
        if (count == k) {
            x = a[i];
            y = 0;
            break;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}