#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> B(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> B[i];
    }

    int sum = B[N-2]; // sum is initially set to the last element of B
    for (int i = 0; i < N-2; i++) {
        sum += min(B[i], B[i+1]); // add the minimum of adjacent elements in B to the sum
    }

    cout << sum << endl;

    return 0;
}