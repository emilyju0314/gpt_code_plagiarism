#include <iostream>

using namespace std;

int main() {
    int n, L, a;
    cin >> n >> L >> a;

    int maxBreaks = 0;
    int lastArrival = 0;
    for (int i = 0; i < n; i++) {
        int t, l;
        cin >> t >> l;
        maxBreaks += (t - lastArrival) / a;
        lastArrival = t + l;
    }

    maxBreaks += (L - lastArrival) / a;

    cout << maxBreaks << endl;

    return 0;
}