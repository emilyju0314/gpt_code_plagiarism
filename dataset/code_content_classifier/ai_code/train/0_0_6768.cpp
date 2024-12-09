#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string bfProgram;
    cin >> bfProgram;

    string binaryCode = "";
    for(char c : bfProgram) {
        switch(c) {
            case '>':
                binaryCode += "1000";
                break;
            case '<':
                binaryCode += "1001";
                break;
            case '+':
                binaryCode += "1010";
                break;
            case '-':
                binaryCode += "1011";
                break;
            case '.':
                binaryCode += "1100";
                break;
            case ',':
                binaryCode += "1101";
                break;
            case '[':
                binaryCode += "1110";
                break;
            case ']':
                binaryCode += "1111";
                break;
        }
    }

    long long unaryNumber = binaryCode.length();
    long long result = pow(2, unaryNumber) - 1;
    
    cout << result % 1000003 << endl;

    return 0;
}