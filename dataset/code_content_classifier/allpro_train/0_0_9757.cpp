#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> sleepTimes(n);
    for(int i = 0; i < n; i++) {
        cin >> sleepTimes[i];
    }

    double totalSum = 0;
    for(int i = 0; i < k; i++) {
        totalSum += sleepTimes[i];
    }

    double currentSum = totalSum;
    for(int i = k; i < n; i++) {
        currentSum = currentSum - sleepTimes[i - k] + sleepTimes[i];
        totalSum += currentSum;
    }

    double weeks = n - k + 1;
    double average = totalSum / weeks;

    cout << fixed << setprecision(10) << average << endl;

    return 0;
}