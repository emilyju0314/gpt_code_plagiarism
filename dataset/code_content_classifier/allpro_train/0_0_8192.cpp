#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Reading the variable descriptions
    map<string, vector<string>> variables;
    vector<string> ops = {"AND", "OR", "XOR"};
    for(int i = 0; i < n; i++) {
        string var, eq, op1, op, op2;
        cin >> var >> eq >> op1;
        if(op1 == "?") {
            variables[var].push_back(op1);
        } else {
            cin >> op >> op2;
            variables[var].push_back(op1 + " " + op + " " + op2);
        }
    }

    string min_num = "", max_num = "";
    int min_score = INT_MAX, max_score = INT_MIN;

    // Iterate through all possible choices of Peter's number
    for(int p = 0; p < (1 << m); p++) {
        int score = 0;

        for(auto it = variables.begin(); it != variables.end(); it++) {
            string var = it->first;
            for(string operation : it->second) {
                size_t pos = operation.find(" ");
                if(pos == string::npos) {
                    if(operation == "?") {
                        score += p;
                    } else {
                        score += stoi(operation, nullptr, 2);
                    }
                } else {
                    string op1 = operation.substr(0, pos);
                    size_t pos2 = operation.find(" ", pos + 1);
                    string op = operation.substr(pos + 1, pos2 - pos - 1);
                    string op2 = operation.substr(pos2 + 1);

                    if(op1 == "?") {
                        op1 = to_string(p);
                    } else if(op1 != "?") {
                        op1 = to_string(stoi(op1, nullptr, 2));
                    }

                    if(op2 == "?") {
                        op2 = to_string(p);
                    } else if(op2 != "?") {
                        op2 = to_string(stoi(op2, nullptr, 2));
                    }

                    if(op == "AND") {
                        score += (stoi(op1) & stoi(op2));
                    } else if(op == "OR") {
                        score += (stoi(op1) | stoi(op2));
                    } else if(op == "XOR") {
                        score += (stoi(op1) ^ stoi(op2));
                    }
                }
            }
        }

        if(score < min_score) {
            min_score = score;
            min_num = bitset<10>(p).to_string().substr(10 - m);
        }
        if(score > max_score) {
            max_score = score;
            max_num = bitset<10>(p).to_string().substr(10 - m);
        }
    }

    cout << min_num << endl;
    cout << max_num << endl;

    return 0;
}