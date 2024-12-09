#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int p, q;
    while (cin >> p >> q) {
        if (p == 0 && q == 0) {
            break;
        }
        
        vector<string> programP(p);
        vector<string> programQ(q);
        
        for (int i = 0; i < p; i++) {
            cin.ignore();
            getline(cin, programP[i]);
        }
        
        for (int i = 0; i < q; i++) {
            cin.ignore();
            getline(cin, programQ[i]);
        }
        
        vector<int> indentations;
        int ro = 0, rc = 0, co = 0, cc = 0, so = 0, sc = 0;
        
        for (int i = 0; i < p; i++) {
            for (char c : programP[i]) {
                if (c == '(') {
                    ro++;
                } else if (c == ')') {
                    rc++;
                } else if (c == '{') {
                    co++;
                } else if (c == '}') {
                    cc++;
                } else if (c == '[') {
                    so++;
                } else if (c == ']') {
                    sc++;
                }
            }
            
            int indentation = (ro - rc) * 9 + (co - cc) * 5 + (so - sc) * 2;
            indentations.push_back(indentation);
        }
        
        for (int i = 0; i < q; i++) {
            int currentIndentation = 0;
            for (char c : programQ[i]) {
                if (c == '(') {
                    currentIndentation += 9;
                } else if (c == ')') {
                    currentIndentation -= 9;
                } else if (c == '{') {
                    currentIndentation += 5;
                } else if (c == '}') {
                    currentIndentation -= 5;
                } else if (c == '[') {
                    currentIndentation += 2;
                } else if (c == ']') {
                    currentIndentation -= 2;
                }
            }
            
            auto it = find(indentations.begin(), indentations.end(), currentIndentation);
            if (it != indentations.end()) {
                cout << distance(indentations.begin(), it) << " ";
            } else {
                cout << "-1 ";
            }
        }
        
        cout << endl;
    }
    
    return 0;
}