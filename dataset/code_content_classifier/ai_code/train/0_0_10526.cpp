#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, ta, b, tb;
    cin >> a >> ta >> b >> tb;

    int start_hour, start_minute;
    char colon;
    cin >> start_hour >> colon >> start_minute;

    int start_time = start_hour * 60 + start_minute; // convert start time to minutes

    int end_time = start_time + ta; // calculate arrival time at city B

    int buses_meeting = 0;
    for(int time = 300; time < 1440; time += b) { // iterate over all possible bus times from city B
        if(time + tb > start_time && time < end_time) { // check if the bus meets Simion
            buses_meeting++;
        }
    }

    cout << buses_meeting << endl;

    return 0;
}