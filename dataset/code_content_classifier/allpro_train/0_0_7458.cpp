#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> permutation;
    vector<int> indices(n, 1);
    iota(permutation.begin(), permutation.end(), 1);

    for (int i = 2; i < n; ++i) {
        cout << "2 " << 1 << " " << i << " " << n << endl;
        int sign;
        cin >> sign;
        if (sign == 1) {
            indices[i] = 0;
        }
    }

    int i;
    for (i = 2; i < n; ++i) {
        if (indices[i] != 0) break;
    }

    permutation[1] = i;

    for (i = 2; i < n; ++i) {
        if (indices[i] != 0) {
            cout << "1 1 " << permutation[1] << " " << i << endl;
            int area;
            cin >> area;
            if (area < 0) {
                permutation[n-1] = i;
            } else {
                permutation[n] = i;
            }
            break;
        }
    }

    for (int i = 2; i < n-1; ++i) {
        if (indices[i] != 0) {
            cout << "2 " << permutation[n-1] << " " << permutation[n] << " " << i << endl;
            int sign;
            cin >> sign;
            if (sign == 1) {
                permutation[i-1] = i;
            } else {
                permutation[i] = i;
            }
        }
    }

    cout << 0 << " ";
    for (int i = 0; i < n; ++i) {
        cout << permutation[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}