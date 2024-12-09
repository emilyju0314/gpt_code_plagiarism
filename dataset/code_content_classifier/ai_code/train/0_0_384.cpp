#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double calculateProbability(int n, vector<int>& balls) {
    sort(balls.begin(), balls.end());

    double favorable_outcomes = (n - 2) * (n - 1);
    double total_outcomes = n * (n - 1) * (n - 2);

    return favorable_outcomes / total_outcomes;
}

int main() {
    int n;
    cin >> n;

    vector<int> balls(n);
    for (int i = 0; i < n; i++) {
        cin >> balls[i];
    }

    double probability = calculateProbability(n, balls);
    cout << fixed << setprecision(10) << probability << endl;

    return 0;
}