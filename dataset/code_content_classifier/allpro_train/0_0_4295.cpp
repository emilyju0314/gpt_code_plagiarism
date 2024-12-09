#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    // Perform n-1 queries to find all elements except the last one
    for(int i = 1; i < n; i++) {
        cout << "? 1 " << i+1 << endl;
        cout.flush();
        cin >> a[i];
    }

    // Find the last element by querying the sum of all elements except the last one
    int sum = 0;
    for(int i = 1; i < n; i++) {
        sum += a[i];
    }
    cout << "? " << n << " " << sum << endl;
    cout.flush();
    cin >> a[0];

    // Output the guessed array
    cout << "! ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}