#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int t = 0;
    vector<char> directions;
    vector<int> steps;

    for (int i = 0; i < n; i++) {
        int clockwise = (s + i) % n;
        int counterclockwise = (s - i + n) % n;

        if (a[clockwise] <= a[counterclockwise]) {
            t += i;
            s = clockwise;
            directions.push_back('+');
            steps.push_back(i);
        } else {
            t += i;
            s = counterclockwise;
            directions.push_back('-');
            steps.push_back(i);
        }
    }

    cout << t << endl;
    for (int i = 0; i < n; i++) {
        cout << directions[i] << steps[i] << endl;
    }

    return 0;
}