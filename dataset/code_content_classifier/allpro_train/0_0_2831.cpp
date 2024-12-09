#include <iostream>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    // Calculate the sum of flavors of all apples
    int total_flavor = N * (2*L + N - 1) / 2;

    // Find the flavor of the apple that needs to be removed to minimize the absolute difference
    int removed_flavor = total_flavor - N;

    cout << removed_flavor << endl;

    return 0;
}