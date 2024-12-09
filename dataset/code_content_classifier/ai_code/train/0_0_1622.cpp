#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    unordered_map<double, int> count;
    int result = 0;

    for (int i = 0; i < N; i++) {
        int wholePart = static_cast<int>(A[i]);
        double decimalPart = A[i] - wholePart;

        if (decimalPart == 0.0) {
            result += count[0.0];
            result += count[wholePart];
        } else {
            result += count[0.0];
            result += count[1.0] + count[wholePart] - count[1.0 * wholePart];
        }

        count[A[i]]++;
    }

    cout << result << endl;

    return 0;
}