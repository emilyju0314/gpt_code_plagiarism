#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    // Find the lexicographically minimum string
    string answer = s;
    for (int i = 0; i < s.length(); i++) {
        string temp = s;
        for (int j = i; j < s.length(); j++) {
            if (temp[j] == 'a') {
                break;
            }
            temp[j] = temp[j] - 1;
            if (temp < answer) {
                answer = temp;
            }
        }
    }

    cout << answer << endl;

    return 0;
}