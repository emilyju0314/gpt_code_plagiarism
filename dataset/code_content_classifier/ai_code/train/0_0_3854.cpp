#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;

    vector<int> marks(k);
    for (int i = 0; i < k; i++) {
        cin >> marks[i];
    }

    int sum = 0;
    for (int mark : marks) {
        sum += mark;
    }

    int remainingTests = n - k;
    int remainingSum = x - sum;

    // Check if remaining sum is possible
    if (remainingSum < remainingTests || remainingSum > remainingTests * p) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> remainingMarks(remainingTests, 1);
    remainingSum -= remainingTests;

    int medianLowerThanY = (n + 1) / 2;

    for (int i = 0; i < remainingTests; i++) {
        if (remainingSum >= p - 1 && remainingMarks[i] < p) {
            remainingMarks[i] = p;
            remainingSum -= p - 1;
        } else if (remainingMarks[i] < y) {
            remainingMarks[i] = y;
            remainingSum -= y;
        } else {
            remainingMarks[i] += remainingSum;
            remainingSum = 0;
        }
    }

    for (int mark : remainingMarks) {
        cout << mark << " ";
    }
    
    return 0;
}