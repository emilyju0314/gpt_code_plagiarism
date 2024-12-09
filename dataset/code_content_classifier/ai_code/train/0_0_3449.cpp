#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;

        vector<pair<int, int>> students; // distance and speed for each student
        for (int i = 0; i < n; i++) {
            int d, v;
            cin >> d >> v;
            students.push_back(make_pair(d, v));
        }

        for (int i = 0; i < n; i++) {
            int laps = 0;
            int distance = students[i].first;
            int speed = students[i].second;

            while (true) {
                laps++;
                if (laps * distance * speed % 231 == 0) {
                    cout << laps << endl;
                    break;
                }
            }
        }
    }

    return 0;
}