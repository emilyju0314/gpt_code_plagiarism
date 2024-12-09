#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long clicks = a[0]; // Start with the first question
    long long total = a[0];

    for (int i = 1; i < n; i++) {
        total *= a[i]; // Total number of possible combinations
        clicks += total; // Add to the total number of clicks
    }

    cout << clicks << endl;

    return 0;
}