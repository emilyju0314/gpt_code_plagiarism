#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int squarePicking(int initial) {
    string str = to_string(initial);
    string square_str = to_string(initial * initial);
    int n = str.length();
    
    // Pad with zeros if needed
    if (square_str.length() < 2 * n) {
        square_str = string(2 * n - square_str.length(), '0') + square_str;
    }
    
    int start = (2 * n - n) / 2;
    string random_str = square_str.substr(start, n);
    
    return stoi(random_str);
}

int main() {
    int d;
    cin >> d;
    
    for (int i = 0; i < d; i++) {
        int s;
        cin >> s;
        
        cout << "Case " << i+1 << ":" << endl;
        for (int j = 0; j < 10; j++) {
            s = squarePicking(s);
            cout << s << endl;
        }
    }
    
    return 0;
}