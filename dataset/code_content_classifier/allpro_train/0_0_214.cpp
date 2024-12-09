#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> requests(n);
    vector<int> schedule(n);

    for (int i = 0; i < n; i++) {
        int si, di;
        cin >> si >> di;
        requests[i] = make_pair(si, di);
    }

    int startTime = 1;
    for (int i = 0; i < n; i++) {
        if (startTime < requests[i].first) {
            schedule[i] = requests[i].first;
            startTime = requests[i].first + 1;
        } else {
            schedule[i] = startTime;
            startTime += requests[i].second;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << schedule[i] << " " << schedule[i] + requests[i].second - 1 << endl;
    }

    return 0;
}