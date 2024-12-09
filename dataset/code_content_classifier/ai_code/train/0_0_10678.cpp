#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += numbers[i];
    }

    int ways = 0;
    int leftSum = 0;
    for (int i = 1; i < n; i++) {
        leftSum += numbers[i - 1];
        if (leftSum * 2 == totalSum) {
            ways++;
        }
    }

    cout << ways << endl;

    return 0;
}