#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> numbers(2*n);
    double sum = 0;

    for(int i = 0; i < 2*n; i++) {
        cin >> numbers[i];
        sum += numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    double diff = sum;
    for(int i = 0; i < 2*n; i++) {
        double currentDiff = abs(sum - 2*numbers[i]);
        diff = min(diff, currentDiff);
    }

    cout << fixed << setprecision(3) << diff/2.0 << endl;

    return 0;
}