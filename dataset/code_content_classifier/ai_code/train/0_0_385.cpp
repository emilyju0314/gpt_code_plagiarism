#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, a, b, T;
    cin >> n >> a >> b >> T;

    string orientation;
    cin >> orientation;

    vector<int> timeToWatch(n); // Array to store time needed to watch each photo for the first time
    vector<int> totalTime(n); // Array to store total time needed to watch each photo

    for (int i = 0; i < n; i++) {
        if (orientation[i] == 'h') {
            timeToWatch[i] = 1;
        } else {
            timeToWatch[i] = a + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        totalTime[i] = timeToWatch[i] + i * a; // Calculate total time needed to watch each photo
    }

    int maxPhotosWatched = 0;
    for (int i = 0; i < n; i++) {
        int currentTime = totalTime[i];
        if (currentTime > T) {
            break;
        }
        int remainingTime = T - currentTime; // Calculate remaining time after watching current photo

        int right = i + 1; // Right side of the current photo
        int left = n - 1; // Left side of the current photo
        int timeToLeft = (i == 0) ? 0 : i * a; // Time needed to move to the left of the current photo
        int timeToRight = (i == 0) ? 0 : (n - i - 1) * a; // Time needed to move to the right of the current photo

        while (right < n && remainingTime >= timeToRight) {
            remainingTime -= timeToRight;
            currentTime += timeToWatch[right] + b; // Time to change orientation
            if (currentTime > T) {
                break;
            }
            maxPhotosWatched = max(maxPhotosWatched, right - i + 1);
            right++;
            timeToRight += a;
        }

        while (left > i && remainingTime >= timeToLeft) {
            remainingTime -= timeToLeft;
            currentTime += timeToWatch[left] + b;
            if (currentTime > T) {
                break;
            }
            maxPhotosWatched = max(maxPhotosWatched, n - left + i + 1);
            left--;
            timeToLeft += a;
        }

        maxPhotosWatched = max(maxPhotosWatched, right - i);
    }

    cout << maxPhotosWatched << endl;

    return 0;
}