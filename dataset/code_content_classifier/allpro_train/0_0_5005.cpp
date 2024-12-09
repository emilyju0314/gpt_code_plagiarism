#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int idx = -1;
    for (int i = 0; i < N - 1; i++) {
        if (a[i] + a[i + 1] >= L) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 1; i <= idx; i++) {
            cout << i << endl;
        }
        for (int i = N - 1; i > idx; i--) {
            cout << i << endl;
        }
    }

    return 0;
}