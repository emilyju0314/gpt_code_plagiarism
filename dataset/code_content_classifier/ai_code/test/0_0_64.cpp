#include <iostream>
#include <string>

using namespace std;

bool isGood(int num) {
    while (num > 0) {
        if (num % 10 == 0) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    string s;
    int x;
    
    cin >> s >> x;
    
    for (int i = 0; i < s.size() - 1; i++) {
        string num1 = s.substr(0, i + 1);
        string num2 = s.substr(i + 1);
        
        int n1 = stoi(num1);
        int n2 = stoi(num2);
        
        if (n1 + n2 == x && isGood(n1) && isGood(n2)) {
            cout << "1 " << i + 1 << endl;
            cout << i + 2 << " " << s.size() << endl;
            break;
        }
    }
    
    return 0;
}