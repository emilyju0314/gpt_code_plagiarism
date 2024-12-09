#include <iostream>
using namespace std;

int main() {
    string line;
    while (true) {
        getline(cin, line);
        if (line == "stop") {
            break;
        } else {
            cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
            cout.flush();
        }
    }
    cout << "done" << endl;
    return 0;
}