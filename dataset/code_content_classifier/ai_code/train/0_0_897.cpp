#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n < 4) {
        cout << -1 << endl;
    } else {
        for(int i = 1; i <= 10000; i++) {
            string num = to_string(i);
            while(num.length() < n) {
                num += '0';
            }
            int numInt = stoi(num);
            if(numInt % 2 == 0 && numInt % 3 == 0 && numInt % 5 == 0 && numInt % 7 == 0) {
                cout << numInt << endl;
                break;
            }
        }
        cout << -1 << endl;
    }

    return 0;
}