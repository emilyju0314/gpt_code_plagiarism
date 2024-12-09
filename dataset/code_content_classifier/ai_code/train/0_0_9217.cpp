#include <iostream>
#include <string>

using namespace std;

int main() {
    string choices[4];
    int minLength = 101, maxLength = 0;
    char luckyChoice = 'C';

    for (int i = 0; i < 4; i++) {
        char choice;
        string description;
        cin >> choice >> description;
        
        choices[i] = description.substr(2); // removing the prefix
        
        int len = choices[i].length();
        if (len < minLength) {
            minLength = len;
        }
        if (len > maxLength) {
            maxLength = len;
        }
    }

    int greatCount = 0;
    char greatChoice;
    for (int i = 0; i < 4; i++) {
        int len = choices[i].length();
        if (len <= minLength/2 || len >= maxLength*2) {
            greatCount++;
            greatChoice = 'A' + i;
        }
    }

    if (greatCount == 1) {
        cout << greatChoice << endl;
    } else {
        cout << luckyChoice << endl;
    }

    return 0;
}