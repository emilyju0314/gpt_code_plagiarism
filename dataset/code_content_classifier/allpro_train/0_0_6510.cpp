#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> p(n);
        map<int, int> pos;

        for (int j = 0; j < n; j++) {
            cin >> p[j];
            pos[p[j]] = j;
        }

        int min_diff = n + 1;
        int start = 0, end = 0;

        for (int j = 1; j < n; j++) {
            int diff = abs(pos[j] - pos[j + 1]);
            if (diff < min_diff) {
                min_diff = diff;
                start = j;
                end = j + 1;
            }
        }

        cout << 2 << endl;
        cout << start << " " << end << endl;
    }

    return 0;
}