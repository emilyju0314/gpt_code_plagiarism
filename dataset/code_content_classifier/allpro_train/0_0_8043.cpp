#include <iostream>
using namespace std;

int main() {
    int matrix[10][10];
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << matrix[0][0] << endl;
    return 0;
}