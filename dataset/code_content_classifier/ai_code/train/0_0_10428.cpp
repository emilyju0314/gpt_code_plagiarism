#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cows(n);
    stack<int> leftCows;
    long long totalMilkLost = 0;

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    for (int i = 0; i < n; i++) {
        if (cows[i] == 0) {
            leftCows.push(i);
        } else {
            totalMilkLost += i - leftCows.size();
        }
    }

    cout << totalMilkLost << endl;

    return 0;
}