#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segments[i] = {l, r};
    }

    int max_right = segments[0].second;
    int covering_segment = 1;

    for (int i = 1; i < n; i++) {
        if (segments[i].second > max_right) {
            covering_segment = -1;
            break;
        }
    }

    if (covering_segment != -1) {
        for (int i = 0; i < n; i++) {
            if (segments[i].second == max_right) {
                covering_segment = i + 1;
                break;
            }
        }
    }

    cout << covering_segment << endl;

    return 0;
}