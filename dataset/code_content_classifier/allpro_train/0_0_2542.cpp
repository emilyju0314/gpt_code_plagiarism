#include <iostream>
#include <string>

using namespace std;

int main() {
    string path;
    cin >> path;

    bool slash = false;
    string result = "";
    for(char c : path) {
        if(c == '/') {
            if(!slash) {
                result += c;
            }
            slash = true;
        } else {
            result += c;
            slash = false;
        }
    }

    cout << result << endl;

    return 0;
}