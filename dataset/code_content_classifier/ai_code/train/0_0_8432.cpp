#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n-1);
    for (int i = 0; i < n-1; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; ++i) {
        long long x = 1, y = 0, curr = i;
        bool terminated = false;

        while (x > 0 && x <= n) {
            y += a[curr];
            x += a[curr];
            curr = x - 1;
            if (curr == i) {
                terminated = true;
                break;
            }
        }

        if (terminated) {
            cout << y << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}