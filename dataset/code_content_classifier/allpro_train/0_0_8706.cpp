#include <iostream>

using namespace std;

int main() {
    char column;
    int row;

    cin >> column >> row;

    int moves = 0;

    if(row - 1 >= 1) moves++;
    if(row + 1 <= 8) moves++;
    if(column - 1 >= 'a') moves++;
    if(column + 1 <= 'h') moves++;
    if(row - 1 >= 1 && column - 1 >= 'a') moves++;
    if(row - 1 >= 1 && column + 1 <= 'h') moves++;
    if(row + 1 <= 8 && column - 1 >= 'a') moves++;
    if(row + 1 <= 8 && column + 1 <= 'h') moves++;

    cout << moves << endl;

    return 0;
}