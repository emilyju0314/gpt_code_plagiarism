#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> passwords(N);
    for (int i = 0; i < N; i++) {
        cin >> passwords[i];
    }

    sort(passwords.begin(), passwords.end());

    string result = "";
    char c = 'a';
    for (string password : passwords) {
        while (password.find(c) != string::npos) {
            c++;
        }
        result += c;
    }

    cout << result << endl;

    return 0;
}