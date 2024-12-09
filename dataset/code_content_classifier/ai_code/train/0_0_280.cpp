#include <iostream>
#include <vector>

using namespace std;

long long calculate_zigzag(vector<int>& arr, int l, int r, int z) {
    long long result = 0;
    for (int i = l - 1; i < r; i++) {
        result += arr[i] * (z % 10);
        z++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int p, v;
            cin >> p >> v;
            arr[p - 1] = v;
        } else if (t == 2) {
            int l, r, z;
            cin >> l >> r >> z;
            cout << calculate_zigzag(arr, l, r, z) << endl;
        }
    }

    return 0;
}