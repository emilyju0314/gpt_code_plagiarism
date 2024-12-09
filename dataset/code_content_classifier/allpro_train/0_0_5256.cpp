#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> problems(n);
    for (int i = 0; i < n; i++) {
        cin >> problems[i];
    }

    int solved = 0;
    for (int i = 0; i < n; i++) {
        if (problems[i] <= k) {
            solved++;
        } else {
            break;
        }
    }

    int rightIndex = n - 1;
    while (rightIndex > 0 && problems[rightIndex] <= k) {
        solved++;
        rightIndex--;
    }

    cout << solved << endl;

    return 0;
}