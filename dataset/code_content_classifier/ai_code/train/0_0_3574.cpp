#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isValidTime(int h, int m, int hour, int minute) {
    if (hour % 10 < h && minute % 10 < m && hour / 10 < m && minute / 10 < h) {
        return true;
    }
    return false;
}

string reflect(int h, int m, int hour, int minute) {
    int reflectedHour = (minute % 10) * 10 + (minute / 10);
    int reflectedMinute = (hour % 10) * 10 + (hour / 10);

    stringstream ss;
    ss << (reflectedHour < h ? reflectedHour : 0);
    ss << ":";
    ss << (reflectedMinute < m ? reflectedMinute : 0);

    return ss.str();
}

string findNearestValidTime(int h, int m, string s) {
    int hour, minute;
    char delimiter;
    stringstream ss(s);
    ss >> hour >> delimiter >> minute;

    while (true) {
        if (isValidTime(h, m, hour, minute)) {
            return s;
        }

        minute++;
        if (minute == m) {
            minute = 0;
            hour = (hour + 1) % h;
        }

        if (hour == stoi(s.substr(0, 2)) && minute == stoi(s.substr(3, 2))) {
            return reflect(h, m, hour, minute);
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int h, m;
        cin >> h >> m;

        string s;
        cin >> s;

        cout << findNearestValidTime(h, m, s) << endl;
    }

    return 0;
}