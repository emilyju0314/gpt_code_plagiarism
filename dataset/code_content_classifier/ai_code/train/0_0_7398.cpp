#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string stripes;
    cin >> stripes;

    int moves = 0;
    for(int i = 1; i < n; i++) {
        if(stripes[i] == stripes[i-1]) {
            moves++;
            if(stripes[i] == '0') {
                stripes[i] = '1';
            } else {
                stripes[i] = '0';
            }
        }
    }

    cout << moves << endl;

    return 0;
}