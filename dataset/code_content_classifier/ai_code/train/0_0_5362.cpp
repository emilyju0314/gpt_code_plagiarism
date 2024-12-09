#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the probability
double calculateProbability(int N, vector<vector<double>>& probabilities, vector<int>& orders) {
    double totalProbability = 1.0;

    for (int i = 0; i < N; i++) {
        double drinkProbability = 0.0;
        for (int j = 0; j < N; j++) {
            drinkProbability += probabilities[i][j] * orders[j];
        }
        totalProbability *= drinkProbability;
    }

    return totalProbability;
}

int main() {
    int testCase = 1;

    while (true) {
        int N;
        cin >> N;

        if (N == 0) {
            break;
        }

        vector<vector<double>> probabilities(N, vector<double>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> probabilities[i][j];
            }
        }

        vector<int> orders(N);
        for (int i = 0; i < N; i++) {
            cin >> orders[i];
        }

        double result = calculateProbability(N, probabilities, orders);
        if (result == 0.0) {
            cout << "Case " << testCase << ": -INFINITY" << endl;
        } else {
            cout << "Case " << testCase << ": " << fixed << setprecision(8) << log(result) << endl;
        }

        testCase++;
    }

    return 0;
}