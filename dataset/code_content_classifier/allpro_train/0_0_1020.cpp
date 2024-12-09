#include <iostream>
using namespace std;

int main() {
    int A, P;
    cin >> A >> P;

    int total_pieces = A * 3 + P;
    int pies = total_pieces / 2;

    cout << pies << endl;

    return 0;
}