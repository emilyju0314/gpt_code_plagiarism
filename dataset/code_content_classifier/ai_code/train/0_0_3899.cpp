#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double minkowskiDistance(const vector<int>& x, const vector<int>& y, int p) {
    double sum = 0.0;
    for (int i = 0; i < x.size(); i++) {
        sum += pow(abs(x[i] - y[i]), p);
    }
    return pow(sum, 1.0/p);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n);
    vector<int> y(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double distance_p1 = minkowskiDistance(x, y, 1);
    double distance_p2 = minkowskiDistance(x, y, 2);
    double distance_p3 = minkowskiDistance(x, y, 3);

    // Calculate the Chebyshev distance
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = abs(x[i] - y[i]);
    }
    double distance_infinity = *max_element(diff.begin(), diff.end());

    cout << fixed;
    cout.precision(6);
    cout << distance_p1 << endl;
    cout << distance_p2 << endl;
    cout << pow(distance_p3, 1.0/3) << endl;
    cout << distance_infinity << endl;

    return 0;
}