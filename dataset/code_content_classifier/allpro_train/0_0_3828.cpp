#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    int output;

    if(a >= 0 && a <= 5) {
        output = 24;
    } else if(a >= 6 && a <= 10) {
        output = 12;
    } else if(a >= 11 && a <= 15) {
        output = 8;
    } else if(a >= 16 && a <= 20) {
        output = 6;
    } else if(a >= 21 && a <= 25) {
        output = 4;
    } else if(a >= 26 && a <= 30) {
        output = 3;
    } else {
        output = 2;
    }
    
    cout << output << endl;

    return 0;
}