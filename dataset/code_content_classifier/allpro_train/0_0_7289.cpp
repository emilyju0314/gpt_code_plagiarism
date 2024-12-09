#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> days(n);
    for(int i = 0; i < n; i++) {
        cin >> days[i];
    }

    long long totalDays = 0;
    for(int i = 0; i < n; i++) {
        totalDays += days[i];
    }

    long long hugs = 0;
    long long maxHugs = 0;
    for(int i = 0; i < n; i++) {
        hugs = 0;
        int temp = x;
        for(int j = i; temp > 0; j = (j + 1) % n) {
            hugs += days[j];
            temp--;
        }
        maxHugs = max(maxHugs, hugs);
    }

    cout << maxHugs << endl;

    return 0;
}