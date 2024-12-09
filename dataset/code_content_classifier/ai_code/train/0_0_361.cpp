#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int d, k;
        cin >> d >> k;

        long long x = 0, y = 0;
        bool utkarshTurn = false;

        while(true) {
            if(utkarshTurn) {
                if(x+k <= y) x += k;
                else if(y+k <= x) y += k;
                else break;
            } else {
                if(x+k <= d) x += k;
                else if(y+k <= d) y += k;
                else break;
            }

            utkarshTurn = !utkarshTurn;
        }

        if(utkarshTurn) cout << "Ashish" << endl;
        else cout << "Utkarsh" << endl;
    }

    return 0;
}