#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    double probability = 0;

    for (int i = 1; i <= N; i++) {
        int score = i;
        int count = 0;
        while (score < K) {
            score *= 2;
            count++;
        }
        probability += 1.0 / N * pow(0.5, count);
    }

    cout << setprecision(12) << probability << endl;

    return 0;
}