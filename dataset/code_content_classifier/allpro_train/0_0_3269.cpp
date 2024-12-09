#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int minTrainFare = min(A, B);
    int minBusFare = min(C, D);

    int totalFare = minTrainFare + minBusFare;

    cout << totalFare << endl;

    return 0;
}