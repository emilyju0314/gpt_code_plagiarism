#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    int x = 0;
    while (x < 31 && (1 << x) - 1 < s[n - 1]) {
        x++;
    }

    cout << x << endl;

    vector<int> magical_permutation(1 << x);
    magical_permutation[0] = 0;

    for (int i = 1; i < (1 << x); i++) {
        for (int j = 0; j < n; j++) {
            if (binary_search(s.begin(), s.end(), magical_permutation[i - 1] ^ (1 << j))) {
                magical_permutation[i] = magical_permutation[i - 1] ^ (1 << j);
                break;
            }
        }
    }

    for (int i = 0; i < (1 << x); i++) {
        cout << magical_permutation[i] << " ";
    }
    cout << endl;

    return 0;
}