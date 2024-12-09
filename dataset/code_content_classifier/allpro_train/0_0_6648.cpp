#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int operations = 0;
    int remaining = 0;

    for (int i = N - 1; i >= 0; i--) {
        int need = max(0, a[i] - remaining);
        operations += need;
        remaining = max(0, remaining - need);

        if (i > 0) {
            remaining = 2 * (remaining - a[i % 2]);
        }
    }

    cout << operations << endl;

    return 0;
}