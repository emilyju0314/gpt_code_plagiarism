#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string n;
    cin >> n;

    vector<int> digits;
    for(char c : n) {
        digits.push_back(c - '0');
    }

    sort(digits.begin(), digits.end());

    vector<int> a, b;
    bool addedZero = false;

    for(int i = digits.size()-1; i >= 0; i--) {
        if(!addedZero && digits[i] == 0) {
            a.push_back(digits[i]);
            b.push_back(digits[i]);
            addedZero = true;
        } else {
            a.push_back(digits[i]);
        }
    }

    sort(digits.begin(), digits.end());

    addedZero = false;

    for(int i = digits.size()-1; i >= 0; i--) {
        if(!addedZero && digits[i] == 0) {
            a.push_back(digits[i]);
            b.push_back(digits[i]);
            addedZero = true;
        } else {
            b.push_back(digits[i]);
        }
    }

    for(int i : a) {
        cout << i;
    }
    cout << endl;

    for(int i : b) {
        cout << i;
    }
    cout << endl;

    return 0;
}