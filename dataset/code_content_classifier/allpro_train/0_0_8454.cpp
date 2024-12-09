#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> albumSizes(m);
    for (int i = 0; i < m; i++) {
        cin >> albumSizes[i];
    }

    vector<int> result(n);
    int currentAlbum = 0;
    int currentIndex = 0;

    while (currentIndex < n) {
        result[currentIndex] = currentAlbum + 1;
        albumSizes[currentAlbum]--;
        if (albumSizes[currentAlbum] == 0) {
            currentAlbum++;
        }
        currentIndex += 2;
    }

    currentIndex = 1;

    while (currentIndex < n) {
        result[currentIndex] = currentAlbum + 1;
        albumSizes[currentAlbum]--;
        if (albumSizes[currentAlbum] == 0) {
            currentAlbum++;
        }
        currentIndex += 2;
    }

    if (currentAlbum < m) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}