#include <iostream>
#include <vector>

using namespace std;

int main() {
    int v;
    cin >> v;

    vector<int> a(9);
    for (int i = 0; i < 9; i++) {
        cin >> a[i];
    }

    int min_paint = *min_element(a.begin(), a.end());

    if (min_paint > v) {
        cout << -1 << endl;
    } else {
        int num_digits = v / min_paint;
        int remainder_paint = v % min_paint;

        for (int i = 8; i >= 0; i--) {
            if (a[i] == min_paint && remainder_paint >= a[i] - min_paint) {
                remainder_paint -= a[i] - min_paint;
                num_digits--;
                cout << i + 1;
                i++;
            }
        }

        for (int i = 0; i < num_digits; i++) {
            cout << min_element(a.begin(), a.end()) - a.begin() + 1;
        }

        cout << endl;
    }

    return 0;
}