#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    string c;
    cin >> a >> c;

    if(c == "R") {
        cin >> b;
        string roman = "";
        while(b > 0) {
            if(b >= 1000) {
                roman += "M";
                b -= 1000;
            }
            else if(b >= 900) {
                roman += "CM";
                b -= 900;
            }
            else if(b >= 500) {
                roman += "D";
                b -= 500;
            }
            else if(b >= 400) {
                roman += "CD";
                b -= 400;
            }
            else if(b >= 100) {
                roman += "C";
                b -= 100;
            }
            else if(b >= 90) {
                roman += "XC";
                b -= 90;
            }
            else if(b >= 50) {
                roman += "L";
                b -= 50;
            }
            else if(b >= 40) {
                roman += "XL";
                b -= 40;
            }
            else if(b >= 10) {
                roman += "X";
                b -= 10;
            }
            else if(b >= 9) {
                roman += "IX";
                b -= 9;
            }
            else if(b >= 5) {
                roman += "V";
                b -= 5;
            }
            else if(b >= 4) {
                roman += "IV";
                b -= 4;
            }
            else {
                roman += "I";
                b -= 1;
            }
        }
        reverse(roman.begin(), roman.end());
        cout << roman << endl;
    } else {
        cin >> b;
        int num = stoi(c, 0, a);
        cout << num << endl;
    }

    return 0;
}