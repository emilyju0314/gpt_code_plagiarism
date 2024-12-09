#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, a, b, T;
    cin >> n >> a >> b >> T;

    string orientation;
    cin >> orientation;

    vector<int> timeRotating(n, b);
    vector<int> timeWatching(n, 1);
    vector<int> timeToMove(n, a);
    vector<int> prefixTime(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        timeWatching[i] += timeWatching[i - 1];
        timeRotating[i] += timeRotating[i - 1];
        timeToMove[i] += timeToMove[i - 1];
        if (orientation[i - 1] == 'h') {
            timeRotating[i] += a;
        }
        prefixTime[i] = prefixTime[i - 1] + timeWatching[i];
    }

    int maxPhotos = 0;

    for (int i = 1; i <= n; i++) {
        int remainingTime = T - prefixTime[i] - timeToMove[i];
        if (remainingTime < 0) {
            break;
        }

        int photosWatched = i;
        if (i < n) {
            photosWatched += (upper_bound(prefixTime.begin(), prefixTime.end(), prefixTime[i] + remainingTime) - prefixTime.begin()) - 1;
        }

        maxPhotos = max(maxPhotos, photosWatched);
    }

    cout << maxPhotos << endl;

    return 0;
}