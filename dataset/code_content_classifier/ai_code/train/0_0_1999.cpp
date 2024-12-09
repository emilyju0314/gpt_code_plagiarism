#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxLength = 1;
    int currentLength = 1;
    double maxMean = (double)(a[0]);
    for (int i = 1; i < n; i++) {
        double mean = (double)(a[i] + (maxMean * currentLength)) / (currentLength + 1);
        if (mean > maxMean) {
            maxMean = mean;
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else {
            maxMean = a[i];
            currentLength = 1;
        }
    }

    cout << maxLength << endl;

    return 0;
}