#include <iostream>
#include <vector>

using namespace std;

int countSquares(int N, int M, vector<int>& h, vector<int>& w) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int height = h[j] - h[i];
            for (int k = 0; k < M; k++) {
                for (int l = k + 1; l < M; l++) {
                    int width = w[l] - w[k];
                    if (height == width) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    int N, M;
    while (cin >> N >> M && N != 0 && M != 0) {
        vector<int> h(N);
        vector<int> w(M);

        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> w[i];
        }

        int squares = countSquares(N, M, h, w);
        cout << squares << endl;
    }

    return 0;
}