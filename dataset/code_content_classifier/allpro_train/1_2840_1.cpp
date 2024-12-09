#include <bits/stdc++.h>
using namespace std;

int main() {
    int w,kijun;
    bool flg=false;
    cin >> w;

    for (int i = 11; i>=0 ; i--){
        kijun = pow(3,i);
        if (w >= (kijun - (kijun / 2)) && w <= (kijun + (kijun / 2))) {
            cout << "+";
            w -= kijun;
            flg = true;
        } else if (w <= (kijun - (kijun / 2) ) * -1 && w >= (kijun + (kijun / 2) ) * -1 ) {
            cout << "-";
            w += kijun;
            flg = true;
        } else if (flg) {
            cout << "0";
        }
    }

    // if (w >= 122 && w <= 202) {
    //     cout << "+";
    //     w -= 243;
    //     flg = true;
    // } else if (w < -122 && w >= -121) {
    //     cout << "-";
    //     w += 243;
    //      flg = true;
    // } else if (flg) {
    //     cout << "0";
    // }

    // if (w >= 41 && w <= 121) {
    //     cout << "+";
    //     w -= 81;
    //     flg = true;
    // } else if (w < -41 && w >= -121) {
    //     cout << "-";
    //     w += 81;
    //      flg = true;
    // } else if (flg) {
    //     cout << "0";
    // }

    // if (w >= 14 && w <= 40) {
    //     cout << "+";
    //     w -= 27;
    //     flg = true;
    // } else if (w < -14 && w >= -40) {
    //     cout << "-";
    //     w += 27;
    //      flg = true;
    // } else if (flg) {
    //     cout << "0";
    // }

    // if (w >= 4 && w <= 13) {
    //     cout << "+";
    //     w -= 9;
    //     flg = true;
    // } else if (w < -4 && w >= -13) {
    //     cout << "-";
    //     w += 9;
    //      flg = true;
    // } else if (flg) {
    //     cout << "0";
    // }

    // if (w > 1 && w <= 3) {
    //     cout << "+";
    //     w -= 3;
    //      flg = true;
    // } else if (w < -1 && w >= -3) {
    //     cout << "-";
    //     w += 3;
    //      flg = true;;
    // } else if (flg){
    //     cout << "0";
    // }

    // if (w >= 1) {
    //     cout << "+";
    // } else if (w <= -1) {
    //     cout << "-";
    // } else {
    //     cout << "0";
    // }

    cout << endl;




    return 0;
}

