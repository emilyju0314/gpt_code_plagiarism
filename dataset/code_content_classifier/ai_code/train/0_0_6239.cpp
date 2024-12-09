#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, string> variables;

    for(int i=0; i<n; i++) {
        string line;
        cin >> line;

        string lvalue = line.substr(0, line.find('='));
        string rvalue = line.substr(line.find('=')+1);

        if(rvalue.find_first_of("#$^&") != string::npos) {
            string arg1 = rvalue.substr(0, rvalue.find_first_of("#$^&"));
            char op = rvalue[rvalue.find_first_of("#$^&")];
            string arg2 = rvalue.substr(rvalue.find_first_of("#$^&")+1);

            string newLine = variables[arg1] + op + variables[arg2];
            variables[lvalue] = newLine;
        } else {
            variables[lvalue] = rvalue;
        }
    }

    map<string, string>::iterator it;
    vector<string> outputLines;

    for(it = variables.begin(); it != variables.end(); it++) {
        if(it->first == "res") {
            outputLines.push_back("res=" + it->second);
        } else {
            outputLines.push_back(it->first + "=" + it->second);
        }
    }

    cout << outputLines.size() << endl;
    for(int i=0; i<outputLines.size(); i++) {
        cout << outputLines[i] << endl;
    }

    return 0;
}