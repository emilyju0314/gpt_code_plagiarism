#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    // Convert string to hours and minutes
    int currentHours, currentMinutes, sleepHours, sleepMinutes;
    char colon;
    stringstream ss;
    ss.str(s);
    ss >> currentHours >> colon >> currentMinutes;
    ss.clear();
    ss.str(t);
    ss >> sleepHours >> colon >> sleepMinutes;

    int totalCurrentMinutes = currentHours * 60 + currentMinutes;
    int totalSleepMinutes = sleepHours * 60 + sleepMinutes;

    int bedtimeMinutes = totalCurrentMinutes - totalSleepMinutes;
    if (bedtimeMinutes < 0) {
        bedtimeMinutes += 24 * 60;
    }

    int bedtimeHours = bedtimeMinutes / 60;
    int bedtimeMinutesRemainder = bedtimeMinutes % 60;

    cout << (bedtimeHours < 10 ? "0" : "") << bedtimeHours << ":" << (bedtimeMinutesRemainder < 10 ? "0" : "") << bedtimeMinutesRemainder << endl;

    return 0;
}