#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int maxNum = max(A, max(B, C));

    int sum = A + B + C - maxNum + maxNum * pow(2, K);

    cout << sum << endl;

    return 0;
}