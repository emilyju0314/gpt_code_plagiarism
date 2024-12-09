#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double t1, t2;
    
    while (cin >> t1 >> t2) {
        if (t1 < 35.5 && t2 < 71.0) {
            cout << "AAA" << endl;
        } else if (t1 < 37.5 && t2 < 77.0) {
            cout << "AA" << endl;
        } else if (t1 < 40.0 && t2 < 83.0) {
            cout << "A" << endl;
        } else if (t1 < 43.0 && t2 < 89.0) {
            cout << "B" << endl;
        } else if (t1 < 50.0 && t2 < 105.0) {
            cout << "C" << endl;
        } else if (t1 < 55.0 && t2 < 116.0) {
            cout << "D" << endl;
        } else if (t1 < 70.0 && t2 < 148.0) {
            cout << "E" << endl;
        } else {
            cout << "NA" << endl;
        }
    }

    return 0;
}