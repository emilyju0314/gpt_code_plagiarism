#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int nextAvailable = 0;
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        if (t[i] >= nextAvailable) {
            time[i] = t[i];
            nextAvailable = t[i] + p;
        } else {
            time[i] = nextAvailable;
            nextAvailable += p;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << time[i] << " ";
    }

    return 0;
}