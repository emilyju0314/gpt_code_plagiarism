#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> schedules(n);
    for (int i = 0; i < n; i++) {
        cin >> schedules[i];
    }

    int rooms = 0;
    for (int i = 0; i < 7; i++) {
        int classes = 0;
        for (int j = 0; j < n; j++) {
            if (schedules[j][i] == '1') {
                classes++;
            }
        }
        rooms = max(rooms, classes);
    }

    cout << rooms << endl;

    return 0;
}