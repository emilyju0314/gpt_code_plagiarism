#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    string sequence;
    cin >> sequence;

    stack<char> st;
    int opening_count = 0;
    int closing_count = 0;

    for (char c : sequence) {
        if (c == '(') {
            opening_count++;
        } else {
            if (opening_count > 0) {
                opening_count--;
            } else {
                closing_count++;
            }
        }
    }

    if (opening_count == 0 && closing_count == 0) {
        cout << closing_count;
    } else {
        cout << "-1";
    }

    return 0;
}