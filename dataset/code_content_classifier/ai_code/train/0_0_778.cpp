#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    vector<int> intersection;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            i++;
        } else if (B[j] < A[i]) {
            j++;
        } else {
            intersection.push_back(A[i]);
            i++;
            j++;
        }
    }

    for (int k = 0; k < intersection.size(); k++) {
        cout << intersection[k] << endl;
    }

    return 0;
}