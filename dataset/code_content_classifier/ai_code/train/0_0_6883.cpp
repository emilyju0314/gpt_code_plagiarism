#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int hours, minutes, totalMinutesPassed, additionalHours, additionalMinutes;
    cin >> hours;
    cin.ignore();
    cin >> minutes;
    cin >> totalMinutesPassed;

    additionalHours = totalMinutesPassed / 60;
    additionalMinutes = totalMinutesPassed % 60;

    minutes += additionalMinutes;
    hours += additionalHours;

    if (minutes >= 60) {
        minutes %= 60;
        hours++;
    }

    hours %= 24;

    cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << endl;

    return 0;
}