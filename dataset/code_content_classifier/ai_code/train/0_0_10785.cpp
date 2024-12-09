#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    int count = 0;
    bool increasing = true, decreasing = true;
    for (int i = 1; i < n; i++) {
        if (seq[i-1] < seq[i]) {
            decreasing = false;
        }
        if (seq[i-1] > seq[i]) {
            increasing = false;
        }
    }

    if (increasing || decreasing) {
        cout << "0" << endl;
    } else {
        int ways = 0;
        for (int i = 0; i < n - 1; i++) {
            if (seq[i] > seq[i+1]) {
                ways++;
            }
        }

        if (ways <= 1 && seq[0] < seq[n-1]) {
            ways++;
        }

        cout << ways << endl;
    }

    return 0;
}