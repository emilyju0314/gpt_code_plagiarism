#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> notes(n);
    for (int i = 0; i < n; i++) {
        cin >> notes[i];
    }

    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (notes[i] == notes[j] || abs(notes[i] - notes[j]) == 1 || abs(notes[i] - notes[j]) == 6) {
                dp1[i] = max(dp1[i], dp2[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (notes[i] == notes[j] || abs(notes[i] - notes[j]) == 1 || abs(notes[i] - notes[j]) == 6) {
                dp2[i] = max(dp2[i], dp1[j] + 1);
            }
        }
    }

    int max_len = 0;
    for (int i = 0; i < n; i++) {
        max_len = max(max_len, max(dp1[i], dp2[i]));
    }

    cout << max_len << endl;

    return 0;
}