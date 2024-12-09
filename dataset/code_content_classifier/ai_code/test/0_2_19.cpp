#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> lengths(n);
        for (int i = 0; i < n; i++) {
            cin >> lengths[i];
        }

        int min_length = lengths[0];
        int curr_pos = 0;

        for (int i = 1; i < n; i++) {
            if (lengths[i] < 0) {
                min_length = max(min_length, curr_pos + lengths[i]);
                curr_pos += lengths[i];
            } else {
                min_length = max(min_length, curr_pos + lengths[i]);
                curr_pos += lengths[i];
            }
        }

        cout << min_length << endl;
    }

    return 0;
}