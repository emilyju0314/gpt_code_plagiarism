#include <iostream>
#include <vector>

using namespace std;

vector<int> findPermutation(vector<int>& p, vector<int>& q, int N, long long K) {
    vector<vector<int>> a(3, vector<int>(N));
    a[0] = p;
    a[1] = q;

    for (int i = 2; i < 3; i++) {
        vector<int> perm(N);
        for (int j = 0; j < N; j++) {
            perm[j] = a[i-2][a[i-1][j]-1];
        }
        a[i] = perm;
    }

    return a[(K - 1) % 3];
}

int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<int> p(N), q(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> q[i];
    }

    vector<int> result = findPermutation(p, q, N, K);

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}