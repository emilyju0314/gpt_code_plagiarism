#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < k1; i++) {
        int min_idx = 0;
        for (int j = 1; j < n; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        A[min_idx]++;
    }

    for (int i = 0; i < k2; i++) {
        int max_idx = 0;
        for (int j = 1; j < n; j++) {
            if (B[j] > B[max_idx]) {
                max_idx = j;
            }
        }
        B[max_idx]--;
    }

    int error = 0;
    for (int i = 0; i < n; i++) {
        error += pow(A[i] - B[i], 2);
    }

    cout << error << endl;

    return 0;
}