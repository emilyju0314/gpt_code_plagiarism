#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, a, d, M;
    cin >> N >> a >> d >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        A[i] = a + i * d;
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (x == 0) {
            for (int j = y - 1, k = z - 1; j < k; j++, k--) {
                swap(A[j], A[k]);
            }
        } else if (x == 1) {
            for (int j = y - 1; j < z; j++) {
                A[j]++;
            }
        } else if (x == 2) {
            for (int j = y - 1; j < z; j++) {
                A[j] /= 2;
            }
        }
    }

    int K;
    cin >> K;
    cout << A[K - 1] << endl;

    return 0;
}