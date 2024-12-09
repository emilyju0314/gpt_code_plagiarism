#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N+1);
    vector<int> B(N);

    for (int i = 0; i < N+1; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    long long total_monsters = 0;
    for (int i = 0; i < N; i++) {
        total_monsters += min(A[i], B[i]);
        total_monsters += min(A[i+1], B[i] - min(A[i], B[i]));
    }

    cout << total_monsters << endl;

    return 0;
}