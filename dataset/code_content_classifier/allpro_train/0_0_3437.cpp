#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        int count = 0;
        for (int j = l - 1; j < r; j++) {
            int min_num = permutation[j];
            int max_num = permutation[j];
            for (int k = j; k < r; k++) {
                min_num = min(min_num, permutation[k]);
                max_num = max(max_num, permutation[k]);
                if (max_num - min_num == k - j) {
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}