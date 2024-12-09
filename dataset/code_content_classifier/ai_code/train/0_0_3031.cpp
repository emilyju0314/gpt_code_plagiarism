#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> sticks(n);
        for (int i = 0; i < n; i++) {
            cin >> sticks[i];
        }

        sort(sticks.begin(), sticks.end());

        long long min_diff = LLONG_MAX;
        vector<int> min_lengths(4);

        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int a = sticks[i];
                int b = sticks[j];

                if (i > 0 && sticks[i-1] == a) continue;
                if (j < n-1 && sticks[j+1] == b) continue;

                int c = a + b;
                int d = abs(a - b);

                long long area = 1LL * a * b;
                long long perimeter = 2LL * (a + b);
                long long diff = (perimeter * perimeter) / area;

                if (diff < min_diff) {
                    min_diff = diff;
                    min_lengths = {a, b, a, b};
                }
            }
        }

        cout << min_lengths[0] << " " << min_lengths[1] << " " << min_lengths[2] << " " << min_lengths[3] << endl;
    }

    return 0;
}