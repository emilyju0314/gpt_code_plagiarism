#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A, B;
    cin >> A >> B;

    int doughCalories;
    cin >> doughCalories;

    vector<int> toppings(N);
    for (int i = 0; i < N; i++) {
        cin >> toppings[i];
    }

    int bestCalories = doughCalories;
    int bestPrice = A;
    int bestCaloriesPerDollar = doughCalories / A;

    for (int i = 0; i < N; i++) {
        int totalPrice = A + (i + 1) * B;
        int totalCalories = doughCalories;
        for (int j = 0; j <= i; j++) {
            totalCalories += toppings[j];
        }
        int caloriesPerDollar = totalCalories / totalPrice;
        if (caloriesPerDollar > bestCaloriesPerDollar) {
            bestCaloriesPerDollar = caloriesPerDollar;
            bestPrice = totalPrice;
            bestCalories = totalCalories;
        }
    }

    cout << bestCaloriesPerDollar << endl;

    return 0;
}