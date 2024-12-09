#include <iostream>
#include <string>

using namespace std;

string convertToCharacter(string input) {
    string output = "";
    char currentChar = ' ';
    int count = 0;
    bool isButton0 = false;
    
    for(char& c : input) {
        if(c == '0') {
            isButton0 = true;
            continue;
        } else if(isButton0) {
            if(c == ' ') {
                output += " ";
            } else {
                count = c - '0';
                while(count > 1) {
                    output += currentChar;
                    count--;
                }
                isButton0 = false;
            }
        } else {
            count = c - '0';
            if(count == 1) {
                output += currentChar;
            } else {
                while(count > 0) {
                    if(count % 2 == 0) {
                        output += ",";
                    } else {
                        output += "'";
                    }
                    count--;
                }
            }
        }
        currentChar = getCharacter(c);
    }
    
    return output;
}

char getCharacter(char button) {
    switch(button) {
        case '1':
            return '\'';
        case '2':
            return 'A';
        case '3':
            return 'D';
        case '4':
            return 'G';
        case '5':
            return 'J';
        case '6':
            return 'M';
        case '7':
            return 'P';
        case '8':
            return 'T';
        case '9':
            return 'W';
        default:
            return ' ';
    }
}

int main() {
    string input;
    
    while(cin >> input) {
        cout << convertToCharacter(input) << endl;
    }
    
    return 0;
}