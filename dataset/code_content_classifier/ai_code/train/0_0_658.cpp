#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cubes(n, vector<int>(6));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> cubes[i][j];
        }
    }

    vector<int> availableDigits(10, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 6; j++) {
            availableDigits[cubes[i][j]] = 1;
        }
    }

    int maxNumber = 1;
    while(true) {
        vector<int> numberDigits;
        int number = maxNumber;
        while(number > 0) {
            numberDigits.push_back(number % 10);
            number /= 10;
        }
        reverse(numberDigits.begin(), numberDigits.end());

        bool canBuildNumber = true;
        for(int digit : numberDigits) {
            if(availableDigits[digit] == 0) {
                canBuildNumber = false;
                break;
            }
        }

        if(!canBuildNumber) {
            break;
        }
        maxNumber++;
    }

    cout << maxNumber - 1 << endl;

    return 0;
}