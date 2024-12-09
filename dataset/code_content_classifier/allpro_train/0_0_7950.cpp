#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    long total = 0;

    for (int i = 0; i < N - 1; i++) {
        total += min(t[i + 1] - t[i], T);
    }

    total += T; // Last person will press the switch and water will emit for T seconds
    cout << total << endl;

    return 0;
}