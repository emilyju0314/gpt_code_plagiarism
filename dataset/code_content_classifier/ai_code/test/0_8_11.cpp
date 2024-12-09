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

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == i + 1) {
            cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1 && a[a[i] - 1] == i + 1) {
            cnt = max(cnt, 2);
        }
    }

    cout << cnt << endl;

    return 0;
}