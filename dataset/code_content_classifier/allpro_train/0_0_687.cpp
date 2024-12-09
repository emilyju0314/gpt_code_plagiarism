#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M;

    vector<int> a(N);
    vector<int> b(M);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int j = 0; j < M; j++) {
        cin >> b[j];
    }

    cin >> Q;

    vector<long long> d(Q);
    vector<int> answer(Q);

    for (int k = 0; k < Q; k++) {
        cin >> d[k];
    }

    vector<long long> sumA(N+1, 0);
    vector<long long> sumB(M+1, 0);

    for (int i = 0; i < N; i++) {
        sumA[i+1] = sumA[i] + a[i];
    }

    for (int j = 0; j < M; j++) {
        sumB[j+1] = sumB[j] + b[j];
    }

    for (int k = 0; k < Q; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                long long total = sumA[i] * b[j] + a[i] * sumB[j];
                if (d[k] <= total) {
                    long long x = d[k];
                    for (int l = 0; l <= i; l++) {
                        x -= b[j];
                        if (x <= 0) {
                            answer[k] = to_string(a[l])[to_string(a[l]).length() + x - 1] - '0';
                            break;
                        }
                    }

                    if (answer[k] == 0) {
                        for (int l = 0; l <= j; l++) {
                            x -= a[i];
                            if (x <= 0) {
                                answer[k] = to_string(b[l])[to_string(b[l]).length() + x - 1] - '0';
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (answer[k] != 0) break;
        }
        if (answer[k] == 0) answer[k] = 'x';
    }

    for (int ans : answer) {
        cout << ans;
    }

    return 0;
}