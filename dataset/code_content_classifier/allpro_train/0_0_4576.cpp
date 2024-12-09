#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isHighProbability(vector<string>& participant, vector<string>& uncle) {
    int countHigh = 0;
    int countLow = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (participant[i][j] != '#' && uncle[i][j] != '#') {
                int pNum = participant[i][j] - '0';
                int uNum = uncle[i][j] - '0';

                if (pNum > uNum) {
                    countHigh++;
                } else if (pNum < uNum) {
                    countLow++;
                }
            }
        }
    }

    return countHigh > countLow;
}

int main() {
    vector<string> participant(7);
    vector<string> uncle(7);
    
    char input;
    while (cin.get(input) && input != '0') {
        for (int i = 0; i < 7; i++) {
            cin >> participant[i];
        }

        for (int i = 0; i < 7; i++) {
            cin >> uncle[i];
        }

        if (isHighProbability(participant, uncle)) {
            cout << "HIGH" << endl;
        } else {
            cout << "LOW" << endl;
        }
    }

    return 0;
}