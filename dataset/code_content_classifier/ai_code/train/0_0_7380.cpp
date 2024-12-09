#include <iostream>
#include <string>
using namespace std;

int findNextLuckyNumber(int a, const string& b) {
    int c = a + 1;
    string mask = "";
    while (true) {
        string strC = to_string(c);
        for (char digit : strC) {
            if (digit == '4' || digit == '7') {
                mask += digit;
            }
        }
        if (mask == b) {
            return c;
        }
        c++;
        mask = "";
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    
    int result = findNextLuckyNumber(a, to_string(b));
    cout << result << endl;
    
    return 0;
}