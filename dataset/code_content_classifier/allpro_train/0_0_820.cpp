#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int open = 0, close = 0;
    for(char c : s) {
        if(c == '(') {
            open++;
        } else {
            if(open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }

    string result = "";
    for(int i = 0; i < close; i++) {
        result += "(";
    }
    result += s;
    for(int i = 0; i < open; i++) {
        result += ")";
    }

    int min_open = 0;
    string current = result;
    for(int i = 0; i < result.size(); i++) {
        if(result[i] == '(') {
            min_open++;
        } else {
            min_open--;
        }
        if(min_open < 0) {
            break;
        }
        if(i == result.size()-1) {
            current = result;
        }
    }

    int start = 0;
    int length = current.size();
    for(int i = 0; i < result.size(); i++) {
        if(current[i] == '(') {
            start = i;
            break;
        }
    }

    for(int i = 0; i < length; i++) {
        cout << current[(start+i)%length];
    }

    return 0;
}