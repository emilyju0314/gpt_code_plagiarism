#include <iostream>
#include <string>

using namespace std;

int main() {
    string start, end;
    int n;

    // Input
    cin >> start >> end;
    cin >> n;

    // Determine the clockwise or counter-clockwise direction
    if ((start == "^" && end == ">") || (start == ">" && end == "v") || (start == "v" && end == "<") || (start == "<" && end == "^")) {
        if (n % 4 == 1) {
            cout << "cw" << endl;
        } else if (n % 4 == 3) {
            cout << "ccw" << endl;
        } else {
            cout << "undefined" << endl;
        }
    } else if ((start == "^" && end == "<") || (start == "<" && end == "v") || (start == "v" && end == ">") || (start == ">" && end == "^")) {
        if (n % 4 == 1) {
            cout << "ccw" << endl;
        } else if (n % 4 == 3) {
            cout << "cw" << endl;
        } else {
            cout << "undefined" << endl;
        }
    }

    return 0;
}