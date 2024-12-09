#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> objects(n);
    for (int i = 0; i < n; i++) {
        cin >> objects[i];
    }

    int totalObjects = 0;
    int remainingSpace = k;
    int maxObjects = 0;

    for (int i = 0; i < n; i++) {
        if (objects[i] <= remainingSpace) {
            remainingSpace -= objects[i];
            totalObjects++;
        } else {
            if (m > 1) {
                m--;
                remainingSpace = k - objects[i];
                maxObjects = max(maxObjects, totalObjects);
                totalObjects = 1;
            } else {
                break;
            }
        }
    }

    maxObjects = max(maxObjects, totalObjects);

    cout << maxObjects << endl;

    return 0;
}