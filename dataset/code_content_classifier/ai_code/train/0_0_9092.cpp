#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2) {
    size_t found = s2.find(s1);
    if (found != string::npos) {
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    vector<string> result;
    for (int i = 1; i <= N; i++) {
        string binary = bitset<32>(i).to_string();
        binary = binary.substr(32 - N);

        bool valid = true;
        for (string s : result) {
            if (isSubstring(s, binary) || isSubstring(binary, s)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            result.push_back(binary);
        }
    }

    cout << result.size() << endl;
    for (string s : result) {
        cout << s << endl;
    }

    return 0;
}