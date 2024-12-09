#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int distinctPhotobooks = 26 * (s.length() + 1) - s.length();
    cout << distinctPhotobooks << endl;

    return 0;
}