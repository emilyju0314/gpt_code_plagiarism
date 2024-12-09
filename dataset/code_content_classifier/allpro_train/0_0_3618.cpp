#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int min_operations = (N - 1) / (K - 1);
    cout << min_operations << endl;

    return 0;
}