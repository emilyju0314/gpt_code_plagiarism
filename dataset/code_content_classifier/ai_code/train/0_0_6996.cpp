#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string table1 = "?D-C'KOPUA";
    string table2 = "ABCDE";
    map<char, char> replaceMap;

    for (int i = 0; i < table1.size(); i++) {
        replaceMap[table1[i]] = table2[i];
    }

    string input;
    while (cin >> input) {
        string output = "";
        string temp = "";
        for (char c : input) {
            if (replaceMap.find(c) != replaceMap.end()) {
                temp += replaceMap[c];
                if (temp.size() == 5) {
                    output += temp;
                    temp = "";
                }
            } else {
                temp += c;
                if (temp.size() > 5) {
                    output += temp.substr(0, 5);
                    temp = temp.substr(5);
                }
            }
        }

        cout << output << endl;
    }

    return 0;
}