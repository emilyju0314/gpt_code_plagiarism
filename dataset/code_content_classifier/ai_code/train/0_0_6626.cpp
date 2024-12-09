#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> fragments(n);
    for (int i = 0; i < n; i++) {
        cin >> fragments[i];
    }

    long long time = 0;
    for (int i = 1; i < n; i++) {
        time += abs(fragments[i] - fragments[i-1]);
    }

    cout << time << endl;

    return 0;
}