#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int countA = 0, countC = 0, countG = 0, countT = 0;

    for(char c : s) {
        if(c == 'A') {
            countA++;
        } else if(c == 'C') {
            countC++;
        } else if(c == 'G') {
            countG++;
        } else if(c == 'T') {
            countT++;
        }
    }

    int maxCount = max({countA, countC, countG, countT});

    if((countA + countC + countG + countT) % 4 == 0) {
        int toFill = maxCount - countA;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                if(countA < maxCount) {
                    s[i] = 'A';
                    countA++;
                } else if(countC < maxCount) {
                    s[i] = 'C';
                    countC++;
                } else if(countG < maxCount) {
                    s[i] = 'G';
                    countG++;
                } else if(countT < maxCount) {
                    s[i] = 'T';
                    countT++;
                }
            }
        }
        cout << s << "\n";
    } else {
        cout << "===\n";
    }

    return 0;
}