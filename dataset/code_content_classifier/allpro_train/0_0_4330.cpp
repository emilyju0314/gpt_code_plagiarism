#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    double K;
    cin >> N >> K;

    vector<double> seq(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    int left = 0, right = 0;
    double product = 1.0;
    int maxLength = 0;

    for (int i = 0; i < N; i++) {
        product *= seq[i];
        while (right < i && product > K) {
            product /= seq[left];
            left++;
        }
        if (product <= K) {
            maxLength = max(maxLength, i - left + 1);
        }
    }

    cout << maxLength << endl;

    return 0;
}