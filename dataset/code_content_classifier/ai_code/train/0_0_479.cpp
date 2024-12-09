#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;

    vector<int> extensions(n);
    for (int i = 0; i < n; i++) {
        cin >> extensions[i];
    }

    if ((a <= h && b <= w) || (a <= w && b <= h)) {
        cout << 0 << endl;
        return 0;
    }

    int minExtensions = INT_MAX;

    for (int i = 0; i < n; i++) {
        int currentH = h, currentW = w;
        int extensionsUsed = 1;

        currentH *= extensions[i];
        currentW *= extensions[i];

        if ((a <= currentH && b <= currentW) || (a <= currentW && b <= currentH)) {
            minExtensions = min(minExtensions, extensionsUsed);
        }

        while (extensionsUsed < n && (currentH < a || currentW < b)) {
            extensionsUsed++;
            currentH *= extensions[i];
            currentW *= extensions[i];

            if ((a <= currentH && b <= currentW) || (a <= currentW && b <= currentH)) {
                minExtensions = min(minExtensions, extensionsUsed);
                break;
            }
        }
    }

    if (minExtensions == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minExtensions << endl;
    }

    return 0;
}