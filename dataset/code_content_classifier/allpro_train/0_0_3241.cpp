#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s, l;
    cin >> n >> s >> l;

    vector<int> strip(n);
    for (int i = 0; i < n; i++) {
        cin >> strip[i];
    }

    int num_pieces = 0, cur_min = INT_MAX, cur_max = INT_MIN, count = 0;

    for (int i = 0; i < n; i++) {
        cur_min = min(cur_min, strip[i]);
        cur_max = max(cur_max, strip[i]);
        count++;

        if (cur_max - cur_min > s) {
            if (count < l) {
                cout << "-1" << endl;
                return 0;
            }

            num_pieces++;
            count = 0;
            cur_min = INT_MAX;
            cur_max = INT_MIN;
        }
    }

    if (count >= l) {
        num_pieces++;
    } else {
        cout << "-1" << endl;
        return 0;
    }

    cout << num_pieces << endl;

    return 0;
}