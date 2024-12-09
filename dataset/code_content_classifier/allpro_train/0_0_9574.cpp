#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            int result = 0;
            for (int j = l - 1; j < r; j++) {
                result = max(result, sequence[j] ^ k);
            }
            cout << result << endl;
        } else {
            int l, r;
            cin >> l >> r;
            vector<int> subsequence(sequence.begin() + l - 1, sequence.begin() + r);
            sort(subsequence.begin(), subsequence.end());
            int count = 1;
            for (int j = 1; j < subsequence.size(); j++) {
                if (subsequence[j] != subsequence[j - 1]) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}