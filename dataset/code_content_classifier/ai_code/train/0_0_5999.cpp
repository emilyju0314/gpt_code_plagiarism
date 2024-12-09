#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkValidType(int n, vector<string>& words) {
    int count = 0;
    for (string word : words) {
        if (word == "pair") {
            count += 2;
        } else if (word == "int") {
            count--;
        }

        if (count < 0) {
            return false;
        }
    }

    return count == 1;
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    if (checkValidType(n, words)) {
        string result = "pair";
        for (int i = 0; i < n - 1; i++) {
            result += "<";
        }
        result += "int";
        for (int i = 0; i < n - 1; i++) {
            result += ">";
        }

        cout << result << endl;
    } else {
        cout << "Error occurred" << endl;
    }

    return 0;
}