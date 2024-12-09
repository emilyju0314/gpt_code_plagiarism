#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    int w;
    cin >> S >> w;

    string result = "";
    int start = 0;
    while (start < S.length()) {
        result += S[start];
        start += w;
    }

    cout << result << endl;

    return 0;
}