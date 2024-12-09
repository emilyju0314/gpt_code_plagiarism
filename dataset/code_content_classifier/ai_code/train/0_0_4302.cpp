#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isKDomminant(char c, int k, string s) {
    for(int i = 0; i <= s.size() - k; i++) {
        bool found = false;
        for(int j = i; j < i + k; j++) {
            if(s[j] == c) {
                found = true;
                break;
            }
        }
        if(!found) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    int k = 1;
    while(true) {
        bool kDominantExists = false;
        for(char c = 'a'; c <= 'z'; c++) {
            if(isKDomminant(c, k, s)) {
                kDominantExists = true;
                break;
            }
        }
        if(kDominantExists) {
            break;
        }
        k++;
    }

    cout << k << endl;

    return 0;
}