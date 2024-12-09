#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;

        if (N == 0 && M == 0) {
            break;
        }

        vector<int> codebook(M);
        for (int i = 0; i < M; i++) {
            cin >> codebook[i];
        }

        vector<int> input(N);
        for (int i = 0; i < N; i++) {
            cin >> input[i];
        }

        vector<int> y(N);
        y[0] = 128;

        for (int i = 1; i < N; i++) {
            int min_error = INT_MAX;
            for (int j = 0; j < M; j++) {
                int current_y = y[i-1] + codebook[j];
                if (current_y < 0) {
                    current_y = 0;
                } else if (current_y > 255) {
                    current_y = 255;
                }
                int error = abs(input[i] - current_y);
                if (error < min_error) {
                    min_error = error;
                    y[i] = current_y;
                }
            }
        }

        int sum_squares = 0;
        for (int i = 0; i < N; i++) {
            sum_squares += pow(input[i] - y[i], 2);
        }

        cout << sum_squares << endl;
    }

    return 0;
}