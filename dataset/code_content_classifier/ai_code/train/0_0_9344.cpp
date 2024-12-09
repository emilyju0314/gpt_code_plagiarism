#include <iostream>
#include <vector>

using namespace std;

string uncompress(string s) {
    vector<int> stack;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            stack.push_back(num);
        } else if (s[i] == '(') {
            continue;
        } else if (s[i] == ')') {
            string tmp = "";
            int repeat = stack.back();
            stack.pop_back();
            while (stack.back() != 0) {
                tmp = tmp + stack.back();
                stack.pop_back();
            }
            stack.pop_back();
            string repeated = "";
            for (int j = 0; j < repeat; j++) {
                repeated = repeated + tmp;
            }
            for (int j = repeated.size() - 1; j >= 0; j--) {
                stack.push_back(repeated[j]);
            }
        } else {
            stack.push_back(s[i]);
        }
    }
    string res = "";
    for (int i = stack.size() - 1; i >= 0; i--) {
        res = res + stack[i];
    }
    return res;
}

int main() {
    string s;
    int i;
    
    while (true) {
        cin >> s >> i;
        if (s == "0" && i == 0) {
            break;
        }
        string uncompressed = uncompress(s);
        if (i < uncompressed.size()) {
            cout << uncompressed[i] << endl;
        } else {
            cout << "0" << endl;
        }
    }

    return 0;
}