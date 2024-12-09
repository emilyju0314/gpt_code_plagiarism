#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), pos(n+1);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    bool possible = true;

    for (int i = 0; i < n; i++) {
        int dist = (pos[b[i]] - pos[b[(i+1)%n] ] + n) % n;

        if (dist != 1 && dist != n-1) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}