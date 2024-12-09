#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    int power = s.length() - 1;
    
    for (char c : s) {
        if (c == '1') {
            cnt += pow(2, power);
        }
        power--;
    }

    cout << cnt << endl;

    return 0;
}