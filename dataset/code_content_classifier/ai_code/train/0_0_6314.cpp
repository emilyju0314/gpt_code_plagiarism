#include <iostream>
#include <iomanip>

using namespace std;

double calculateProbability(int N, int M) {
    double result = 0.0;
    for (int i = 1; i <= M; i++) {
        result += pow((double)i / N, N) * pow((double)(N - i) / N, N);
    }
    return result;
}

int main() {
    int N, M;
    cin >> N >> M;

    double probability = calculateProbability(N, M);
    cout << fixed << setprecision(8) << probability << endl;

    return 0;
}