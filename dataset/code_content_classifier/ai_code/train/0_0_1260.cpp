#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s, l;
    cin >> n >> s >> l;

    vector<int> ai(n);
    for (int i = 0; i < n; i++) {
        cin >> ai[i];
    }

    int pieces = 0;
    int currentMin = ai[0];
    int currentMax = ai[0];

    for (int i = 0; i < n; i++) {
        currentMin = min(currentMin, ai[i]);
        currentMax = max(currentMax, ai[i]);

        if (currentMax - currentMin > s) {
            cout << -1 << endl;
            return 0;
        }

        if (i == n - 1 || (ai[i] != ai[i + 1] && abs(ai[i] - currentMin) > s && abs(ai[i] - currentMax) > s)) {
            if (i < n - 1) {
                currentMin = min(ai[i+1], ai[i]);
                currentMax = max(ai[i+1], ai[i]);
            }
            pieces++;
        }
    }

    cout << pieces << endl;

    return 0;
}