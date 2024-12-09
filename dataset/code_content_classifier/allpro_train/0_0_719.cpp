#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string line;
    queue<int> timestamps;
    int count = 0;
    bool found = false;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string timestamp;
        ss >> timestamp;

        int hour, minute, second;
        char c;
        ss >> hour >> c >> minute >> c >> second;

        int curr_time = hour * 3600 + minute * 60 + second;
        timestamps.push(curr_time);
        count++;

        while (!timestamps.empty() && curr_time - timestamps.front() >= n) {
            timestamps.pop();
            count--;
        }

        if (count >= m) {
            found = true;
            cout << timestamp << endl;
            break;
        }
          
    }

    if (!found) {
        cout << "-1" << endl;
    }

    return 0;
}