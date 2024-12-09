Here is a C++ program to solve the problem:

'''
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y, b, p;
        cin >> x >> y >> b >> p;

        int total = x * b + y * p;
        int cheapest = total;

        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= p; k++) {
                int current_total = x * max(0, b - j) + y * max(0, p - k);
                if ((b - j) + (p - k) >= 5 && j + k >= 2) {
                    current_total *= 0.8;
                }
                cheapest = min(cheapest, current_total);
            }
        }

        cout << cheapest << endl;
    }

    return 0;
}
'''

This program takes the input for the number of days (N) and for each day, takes the bathing ticket fee (x), pool ticket fee (y), number of bathing tickets used (b), and number of pool tickets used (p). It then calculates the total price without any discounts and iterates over all possible combinations of unused tickets that could lead to a discount. Finally, it outputs the cheapest total price for each day.