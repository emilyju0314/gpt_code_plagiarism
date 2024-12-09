#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> recipes(200001, 0);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        recipes[l]++;
        recipes[r + 1]--;
    }

    for (int i = 1; i <= 200000; i++) {
        recipes[i] += recipes[i - 1];
    }

    vector<int> admissible(200001, 0);
    for (int i = 1; i <= 200000; i++) {
        if (recipes[i] >= k) {
            admissible[i] = 1;
        }
        admissible[i] += admissible[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << admissible[b] - admissible[a - 1] << endl;
    }

    return 0;
}