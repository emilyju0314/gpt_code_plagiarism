#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> chapters(n);
    for (int i = 0; i < n; i++) {
        cin >> chapters[i];
    }

    long long totalTime = 0;
    long long currTime = x;

    for (int i = 0; i < n; i++) {
        totalTime += currTime * chapters[i];
        if (currTime > 1) {
            currTime--;
        }
    }

    cout << totalTime << endl;

    return 0;
}