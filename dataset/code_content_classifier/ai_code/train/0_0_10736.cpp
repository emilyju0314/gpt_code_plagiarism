#include <iostream>
#include <string>
#include <vector>

using namespace std;

int evaluateHash(string s, string p) {
    vector<int> stack;
    for(char c : s) {
        if(c == ' ') {
            continue;
        } else if(c == '+' || c == '*' || c == '^' || c == '[') {
            stack.push_back(c);
        } else if(c == ']') {
            int op = stack.back();
            stack.pop_back();
            int hash2 = stack.back();
            stack.pop_back();
            int hash1 = stack.back();
            stack.pop_back();
            if(op == '+') {
                stack.push_back(hash1 | hash2);
            } else if(op == '*') {
                stack.push_back(hash1 & hash2);
            } else if(op == '^') {
                stack.push_back(hash1 ^ hash2);
            }
        } else {
            if(c == 'a') {
                stack.push_back((p[0] - '0'));
            } else if(c == 'b') {
                stack.push_back((p[1] - '0'));
            } else if(c == 'c') {
                stack.push_back((p[2] - '0'));
            } else if(c == 'd') {
                stack.push_back((p[3] - '0'));
            }
        }
    }
    return stack.back();
}

int main() {
    string s, p;

    while(true) {
        getline(cin, s);
        if(s == ".") {
            break;
        }
        getline(cin, p);

        int hashValue = evaluateHash(s, p);
        int count = 0;
        for(int i = 0; i < 10000; i++) {
            p = to_string(i);
            if(evaluateHash(s, p) == hashValue) {
                count++;
            }
        }

        cout << hashValue << " " << count << endl;
    }

    return 0;
}