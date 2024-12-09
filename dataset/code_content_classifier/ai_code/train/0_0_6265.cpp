#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> destinations(n);
    for (int i = 0; i < n; i++) {
        cin >> destinations[i];
    }

    sort(destinations.begin(), destinations.end());

    long long totalDistance = 0;
    for (int i = 1; i < n; i++) {
        totalDistance += abs(destinations[i] - destinations[i-1]) * (long long) i * (long long) (n - i); 
    }

    long long numerator = 2 * totalDistance;
    long long denominator = n * (n - 1);

    for (long long i = 2; i <= numerator; i++) {
        if (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;
            i = 1;
        }
    }

    cout << numerator << " " << denominator;

    return 0;
}