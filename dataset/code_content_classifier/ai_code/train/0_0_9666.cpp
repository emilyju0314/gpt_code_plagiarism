#include <iostream>
#include <string>
using namespace std;

int main() {
    int format;
    string time;
    
    cin >> format >> time;
    
    if (format == 12) {
        if (time[0] > '1') {
            time[0] = '0';
        }
        if (time[0] == '1' && time[1] > '2') {
            time[0] = '0';
        }
        if (time[3] > '5') {
            time[3] = '0';
        }
    } else {
        if (time[0] > '2') {
            time[0] = '0';
        }
        if (time[0] == '2' && time[1] > '3') {
            time[0] = '0';
        }
        if (time[3] > '5') {
            time[3] = '0';
        }
    }
    
    cout << time << endl;
    
    return 0;
}