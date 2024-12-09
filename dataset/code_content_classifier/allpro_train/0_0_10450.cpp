#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> students(n);
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            cin >> students[i].first >> students[i].second;
        }

        int currTime = 1;
        for (int i = 0; i < n; i++) {
            if (currTime <= students[i].first) {
                result[i] = students[i].first;
                currTime = students[i].first + 1;
            } else if (currTime <= students[i].second) {
                result[i] = currTime;
                currTime++;
            } else {
                result[i] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}