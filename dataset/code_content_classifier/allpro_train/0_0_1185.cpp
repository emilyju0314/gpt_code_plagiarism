#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string time;
    cin >> time;

    stringstream ss(time);
    int hour, minute;
    char colon;
    ss >> hour >> colon >> minute;

    double hour_angle = hour % 12 * 30 + minute * 0.5;
    double minute_angle = minute * 6;

    cout << fixed << setprecision(1) << hour_angle << " " << minute_angle << endl;

    return 0;
}