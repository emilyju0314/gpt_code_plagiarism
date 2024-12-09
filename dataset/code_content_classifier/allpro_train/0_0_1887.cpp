#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int gcd_val = A[0];
    for(int i = 1; i < N; i++) {
        gcd_val = __gcd(gcd_val, A[i]);
    }

    int max_val = *max_element(A.begin(), A.end());

    if(K <= max_val && K % gcd_val == 0) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}