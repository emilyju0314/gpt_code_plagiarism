#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 7;
const int COLS = 8;
const int ROWS_TOTAL = 15;
const int COLS_TOTAL = 31;

vector<vector<char>> picture(ROWS, vector<char>(COLS));
vector<vector<char>> arrangement(ROWS_TOTAL, vector<char>(COLS_TOTAL, '.'));

void readInput() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> picture[i][j];
        }
    }
}

void placePills() {
    // Your code to place the pills in the box goes here
    // You may need to create helper functions to determine the optimal arrangement
}

void printOutput(int maxMatching) {
    cout << maxMatching << endl;
    for (int i = 0; i < ROWS_TOTAL; i++) {
        for (int j = 0; j < COLS_TOTAL; j++) {
            cout << arrangement[i][j];
        }
        cout << endl;
    }
}

int main() {
    readInput();
    
    // Your code to find the maximum number of matching colors in all 56 cells goes here
    int maxMatching = 0;
    
    placePills();
    printOutput(maxMatching);
    
    return 0;
}