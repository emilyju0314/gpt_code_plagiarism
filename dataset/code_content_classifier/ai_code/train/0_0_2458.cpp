#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> radii(n);
    for (int i = 0; i < n; i++) {
        cin >> radii[i];
    }

    long long totalTime = 0;
    long long currTime = 0;

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            currTime += radii[i-1];
        }
        currTime = max(currTime, (long long)i);

        totalTime += currTime;
    }

    cout << totalTime << endl;

    return 0;
}