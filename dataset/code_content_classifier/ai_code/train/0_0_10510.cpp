#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);

    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    for (int k = 2; k <= n; k++) {
        vector<int> temp(n);
        int r = n / k;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < k; j++) {
                temp[i * k + j] = permutation[(i + 1) * k - j - 1];
            }
        }
        for (int i = r * k; i < n; i++) {
            temp[i] = permutation[i];
        }
        permutation = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;

    return 0;
}