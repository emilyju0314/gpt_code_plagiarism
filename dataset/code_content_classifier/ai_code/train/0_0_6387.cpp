#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N-1), b(N-1);
    for(int i = 0; i < N-1; i++) {
        cin >> a[i] >> b[i];
    }

    int A = N-1, B = 1;

    for(int i = 0; i < N-1; i++) {
        int dist = min(a[i]-1, N-a[i]) + min(b[i]-1, N-b[i]);
        A = min(A, dist);
        B = max(B, dist);
    }

    cout << A << " " << B << endl;

    return 0;
}