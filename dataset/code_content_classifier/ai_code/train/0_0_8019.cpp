#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> marks(n);
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    vector<int> assignment(n);
    double maxAverage = 0;

    for (int i = 0; i <= a; i++) {
        int j = a - i;
        double sum1 = 0, sum2 = 0;
        
        for (int k = 0; k < n; k++) {
            if ((i > 0 && a > 0) || (j > 0 && b == 0)) {
                assignment[k] = 1;
                sum1 += marks[k];
                a--;
            } else {
                assignment[k] = 2;
                sum2 += marks[k];
            }
        }

        double average = (sum1 / (double)(a==0 ? 1 : a)) + (sum2 / (double)(b==0? 1 : b));

        if (average > maxAverage) {
            maxAverage = average;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << assignment[i] << " ";
    }

    return 0;
}