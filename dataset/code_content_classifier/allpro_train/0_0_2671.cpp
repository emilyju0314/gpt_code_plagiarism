#include <iostream>
#include <string>

using namespace std;

bool isValid(int a, int b, int c) {
    if (a + b == c) {
        return true;
    }
    return false;
}

int main() {
    string line;
    
    while (getline(cin, line)) {
        string num1 = "";
        string num2 = "";
        string num3 = "";
        
        int i = 0;
        for (; line[i] != '+'; i++) {
            num1 += line[i];
        }
        i++;
        for (; line[i] != '='; i++) {
            num2 += line[i];
        }
        i++;
        for (; i < line.size(); i++) {
            num3 += line[i];
        }
        
        bool found = false;
        
        for (int x = 0; x <= 9; x++) {
            string num1_copy = num1;
            string num2_copy = num2;
            string num3_copy = num3;
            
            for (char &c : num1_copy) {
                if (c == 'X') {
                    c = x + '0';
                }
            }
            for (char &c : num2_copy) {
                if (c == 'X') {
                    c = x + '0';
                }
            }
            for (char &c : num3_copy) {
                if (c == 'X') {
                    c = x + '0';
                }
            }
            
            int a = stoi(num1_copy);
            int b = stoi(num2_copy);
            int c = stoi(num3_copy);
            
            if (isValid(a, b, c)) {
                cout << x << endl;
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "NA" << endl;
        }
    }
    
    return 0;
}