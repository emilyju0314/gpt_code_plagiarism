#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // Concatenate a and b
    string concat = to_string(a) + to_string(b);

    // Convert concatenated string to integer
    int num = stoi(concat);

    // Check if the concatenated number is a square number
    int root = sqrt(num);
    if (root*root == num) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}