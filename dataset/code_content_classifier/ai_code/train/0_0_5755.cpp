#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nA, nB, k, m;
    cin >> nA >> nB;
    cin >> k >> m;

    vector<int> A(nA);
    vector<int> B(nB);

    for (int i = 0; i < nA; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < nB; i++) {
        cin >> B[i];
    }

    if (A[k-1] < B[nB - m]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}