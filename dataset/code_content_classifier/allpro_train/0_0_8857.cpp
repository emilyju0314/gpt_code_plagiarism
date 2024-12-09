#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkHammingDistance(const string& s1, const string& s2, int h) {
    int count = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            count++;
        }
    }
    return count == h;
}

int main() {
    vector<int> input(6);

    for (int i = 0; i < 6; i++) {
        cin >> input[i];
    }

    for (int len = 1; len <= 105; len++) {
        string s1(len, 'a');
        string s2(len, 'a');
        string s3(len, 'a');
        string s4(len, 'a');

        if (input[0] + input[1] + input[2] == 0) {
            continue;
        }

        for (int i = 0; i < len; i++) {
            s2[i] = 'b';
            s3[i] = 'b';
            s4[i] = 'b';
        }

        int h12 = input[0];
        int h13 = input[1];
        int h14 = input[2];
        int h23 = input[3];
        int h24 = input[4];
        int h34 = input[5];

        if (checkHammingDistance(s1, s2, h12) && checkHammingDistance(s1, s3, h13) && checkHammingDistance(s1, s4, h14) &&
            checkHammingDistance(s2, s3, h23) && checkHammingDistance(s2, s4, h24) && checkHammingDistance(s3, s4, h34)) {
            cout << len << endl;
            cout << s1 << endl;
            cout << s2 << endl;
            cout << s3 << endl;
            cout << s4 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}