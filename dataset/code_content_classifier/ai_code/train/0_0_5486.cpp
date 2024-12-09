#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n << endl;

    // Print the permutation in descending order
    for (int i = n; i >= 0; i--) {
        cout << i << " ";
    }
    
    return 0;
}