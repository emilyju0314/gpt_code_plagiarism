#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, T;
    cin >> n >> T;

    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int eatenBowls = 0;
    int timePassed = 0;
    int maxTimeToEat = 0;

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            maxTimeToEat = t[i];
        } else {
            maxTimeToEat = max(maxTimeToEat, t[i]);
        }

        timePassed += t[i];

        if(timePassed <= T) {
            eatenBowls++;
        } else {
            break;
        }

        if(timePassed + maxTimeToEat > T) {
            break;
        }
    }

    cout << eatenBowls << endl;

    return 0;
}