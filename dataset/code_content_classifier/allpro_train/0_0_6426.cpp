#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    sort(times.begin(), times.end());

    int totalTime = 10; // Time taken to read the problems
    int solvedProblems = 0;
    int penaltyTime = 0;

    for (int i = 0; i < n; i++) {
        if (totalTime + times[i] <= 300) {
            totalTime += times[i];
            solvedProblems++;
            penaltyTime += totalTime - 300;
        }
    }

    cout << solvedProblems << " " << penaltyTime << endl;

    return 0;
}