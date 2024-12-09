#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> A(3);
    for(int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int min_cost = min(abs(A[1] - A[0]) + abs(A[2] - A[1]),
                       abs(A[2] - A[1]) + abs(A[1] - A[0]));

    cout << min_cost << endl;

    return 0;
}