#include <iostream>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    long long x = n / k;
    long long remaining_questions = n - x;

    if (m <= remaining_questions) {
        cout << m << endl;
    } else {
        long long max_score = x * (k-1);
        long long remaining_correct = m - remaining_questions;
        long long min_score = max_score - remaining_correct;
        cout << min_score << endl;
    }

    return 0;
}