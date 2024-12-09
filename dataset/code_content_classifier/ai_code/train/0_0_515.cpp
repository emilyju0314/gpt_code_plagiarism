#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    long long totalWeight = 0;
    long long maxWeightA = 0, maxWeightB = 0;
    long long sumA = 0, sumB = 0;

    for (int i = 0; i < n; i++) {
        sumA += a[i];
        sumB += b[i];
        maxWeightA = max(maxWeightA, sumA + sumB);
        maxWeightB = max(maxWeightB, sumB + sumA);
        totalWeight = max(totalWeight, maxWeightA);
        totalWeight = max(totalWeight, maxWeightB);
    }

    cout << totalWeight << endl;

    return 0;
}