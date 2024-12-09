#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    double total_x = 0, total_y = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double x = static_cast<double>(C[i]*B[j] - C[j]*B[i]) / (A[i]*B[j] - A[j]*B[i]);
            double y = static_cast<double>(C[i]*A[j] - C[j]*A[i]) / (B[i]*A[j] - B[j]*A[i]);
            total_x += x;
            total_y += y;
        }
    }

    double avg_x = total_x / (N*(N-1)/2);
    double avg_y = total_y / (N*(N-1)/2);

    cout << fixed;
    cout.precision(15);
    cout << avg_x << " " << avg_y << endl;

    return 0;
}