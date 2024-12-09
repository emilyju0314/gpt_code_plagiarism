#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int max_length = 0;
    int current_length = 0;

    for(char c : S) {
        if(c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            current_length++;
            max_length = max(max_length, current_length);
        } else {
            current_length = 0;
        }
    }

    cout << max_length << endl;

    return 0;
}