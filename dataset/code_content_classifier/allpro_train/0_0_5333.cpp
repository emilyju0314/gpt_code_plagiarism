#include <iostream>

using namespace std;

int main() {
    long long n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;

    long long cycle = (n * m) * 2 - 2;
    long long fullCycles = k / cycle;
    long long remainingQuestions = k % cycle;
    
    long long maxQuestions = fullCycles * 2;
    if (remainingQuestions > 0) {
        maxQuestions += (remainingQuestions <= n*m) ? 1 : 2;
    }

    long long minQuestions = fullCycles * 2;
    if (remainingQuestions >= 2) {
        remainingQuestions -= 2;
        minQuestions++;
        minQuestions += min(remainingQuestions, n*m);
    }

    long long sergQuestions = fullCycles;
    if (remainingQuestions >= 1) {
        sergQuestions++;
    }

    cout << maxQuestions << " " << minQuestions << " " << sergQuestions << endl;

    return 0;
}