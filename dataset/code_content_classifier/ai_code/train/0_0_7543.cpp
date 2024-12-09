#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int count_4 = 0, count_7 = 0;
    for (char c : s) {
        if (c == '4') {
            count_4++;
        } else if (c == '7') {
            count_7++;
        }
    }

    if (count_4 == 0 && count_7 == 0) {
        cout << "-1" << endl;
    } else if (count_4 >= count_7) {
        cout << "4" << endl;
    } else {
        cout << "7" << endl;
    }

    return 0;
}