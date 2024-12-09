#include <iostream>
#include <string>

using namespace std;

int main() {
    string t;
    cin >> t;

    string s(t);

    // Send initial query
    cout << "? " << s << endl;
    cout.flush();
    string t1;
    cin >> t1;

    // Send second query
    string s2(s);
    swap(s2[0], s2[1]); // Perform one swap
    cout << "? " << s2 << endl;
    cout.flush();
    string t2;
    cin >> t2;

    // Send third query
    string s3(s);
    swap(s3[1], s3[2]); // Perform another swap
    cout << "? " << s3 << endl;
    cout.flush();
    string t3;
    cin >> t3;

    // Deduce the original string s
    string original_s = t;
    if (t1 == t2) {
        original_s = s3;
    } else if (t1 == t3) {
        original_s = s2;
    }

    // Output the original string
    cout << "! " << original_s << endl;
    cout.flush();

    return 0;
}