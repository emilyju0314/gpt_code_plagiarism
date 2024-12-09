#include<iostream>
using namespace std;

int main() {
    string line;
    bool isAmplifying = false;
    string prevLine = "";

    while (getline(cin, line)) {
        if (line.find("#") == 0) {
            isAmplifying = true;
            cout << line << endl;
        } else {
            if (isAmplifying) {
                cout << line << endl;
            } else {
                if (prevLine != "") {
                    cout << prevLine + line;
                } else {
                    cout << line;
                }
            }
        }
        prevLine = line;
    }

    return 0;
}