#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp(r - l + 1);
    long long inversions = 0;

    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            inversions += m - i + 1;
            inversions %= MOD;
            temp[k++] = arr[j++];
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }

    while (j <= r) {
        temp[k++] = arr[j++];
    }

    for (int p = l; p <= r; p++) {
        arr[p] = temp[p - l];
    }

    return inversions % MOD;
}

long long mergeSort(vector<int>& arr, int l, int r) {
    long long inversions = 0;

    if (l < r) {
        int m = l + (r - l) / 2;
        inversions += mergeSort(arr, l, m);
        inversions += mergeSort(arr, m + 1, r);
        inversions += merge(arr, l, m, r);
    }

    return inversions % MOD;
}

int main() {
    int n;
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    long long totalInversions = mergeSort(permutation, 0, n - 1);

    cout << totalInversions << endl;

    return 0;
}