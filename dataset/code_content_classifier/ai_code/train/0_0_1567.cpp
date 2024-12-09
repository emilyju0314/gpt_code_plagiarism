#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    int triangles = 0;
    int remaining = 0;

    for (int i = 0; i < n; i++) {
        if (sticks[i] % 2 == 0) {
            triangles += sticks[i] / 2;
        } else {
            triangles += (sticks[i] - 1) / 2;
            if (remaining > 0) {
                triangles++;
                remaining--;
            }
            remaining = 1;
        }
    }

    cout << triangles << endl;

    return 0;
}