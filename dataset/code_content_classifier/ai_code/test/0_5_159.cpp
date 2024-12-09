#include <iostream>
#include <vector>

using namespace std;

bool isPerfectSquare(long long n) {
    long long sqrtN = sqrt(n);
    return sqrtN * sqrtN == n;
}

int main() {
    int n;
    cin >> n;

    // Store the subset in a vector
    vector<int> subset;

    for(int i = 1; i <= n; i++) {
        // Check if i! * i! is a perfect square
        if(isPerfectSquare((long long)factorial(i) * factorial(i))) {
            subset.push_back(i);
        }
    }

    // Print the size of the subset
    cout << subset.size() << endl;

    // Print the subset itself
    for(auto num : subset) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}