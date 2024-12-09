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

    vector<int> c(n, -1);

    for (int i = 0; i < n; i++) {
        int maxCoolness = a[i];
        int tracksListened = 1;
        int nextTrack = (i + 1) % n;

        while (a[nextTrack] >= maxCoolness / 2) {
            maxCoolness = max(maxCoolness, a[nextTrack]);
            nextTrack = (nextTrack + 1) % n;
            tracksListened++;
            if (tracksListened > n) {
                break;
            }
        }

        if (tracksListened <= n) {
            c[i] = tracksListened;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}