#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int zeros = 0, ones = 0;
    for(char ch : s) {
        if(ch == '0') {
            zeros++;
        } else {
            ones++;
        }
    }

    string result = "";
    int t_zeros = 0, t_ones = 0;
    for(char ch : t) {
        if(ch == '0') {
            t_zeros++;
        } else {
            t_ones++;
        }
    }

    if(zeros >= t_zeros && ones >= t_ones) {
        result = t;

        for(int i = 0; i < zeros - t_zeros; i++) {
            result += '0';
        }
        for(int i = 0; i < ones - t_ones; i++) {
            result += '1';
        }
    } else {
        result = s;
    }

    cout << result << endl;

    return 0;
}