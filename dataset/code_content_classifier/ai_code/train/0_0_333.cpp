#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    string str, sub1, sub2;
    cin >> str >> sub1 >> sub2;

    // Find the index where sub1 first appears in str
    size_t pos1 = str.find(sub1);

    // Find the index where sub2 first appears in str after index x
    size_t pos2 = str.find(sub2, x);

    // Check if both substrings appear in the right order and within the specified indices
    if (pos1 != string::npos && pos2 != string::npos && pos2 > pos1) {
        cout << pos1 + 1 << " " << pos2 + sub2.length() << endl;
    } else {
        cout << "-1 -1" << endl;
    }

    return 0;
}