#include <iostream>

using namespace std;

int main() {
    int X, A, B;
    cin >> X >> A >> B;

    int cakePrice = A;
    int donutPrice = B;

    int remainingAmount = X - A;
    int numDonuts = remainingAmount / B;
    int amountLeft = remainingAmount - (numDonots * B);

    cout << amountLeft << endl;

    return 0;
}