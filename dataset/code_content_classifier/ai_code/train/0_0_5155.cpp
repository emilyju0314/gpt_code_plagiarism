#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < i; j++) {
            if (A[j] >= (i + k)) {
                count++;
            }
        }
        A[i] = count + 1;
    }

    sort(A.begin(), A.end());

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        int idx = 0;
        while (B[idx] == 0) {
            idx++;
        }
        B[idx]--;
        result[i] = A[idx];
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}