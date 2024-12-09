#include <iostream>
#include <string>

using namespace std;

bool isTypeA(string snake) {
    if (snake.size() < 7) {
        return false;
    }
    
    if (snake.substr(0, 2) != ">'") {
        return false;
    }
    
    size_t equalPos = snake.find('=');
    if (equalPos == string::npos) {
        return false;
    }
    
    size_t hashPos = snake.find('#');
    if (hashPos == string::npos) {
        return false;
    }
    
    size_t tildePos = snake.find('~');
    if (tildePos == string::npos) {
        return false;
    }
    
    if (tildePos - hashPos != hashPos - equalPos) {
        return false;
    }
    
    return true;
}

bool isTypeB(string snake) {
    if (snake.size() < 12) {
        return false;
    }
    
    size_t arrowPos = snake.find(">^");
    if (arrowPos == string::npos) {
        return false;
    }
    
    size_t tildePos = snake.find("~~");
    if (tildePos == string::npos) {
        return false;
    }
    
    size_t equalPos = snake.find('Q', arrowPos);
    while (equalPos != string::npos && equalPos < tildePos) {
        if (snake[equalPos+1] != '=') {
            return false;
        }
        equalPos = snake.find('Q', equalPos+1);
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string snake;
        cin >> snake;
        
        if (isTypeA(snake)) {
            cout << "A" << endl;
        } else if (isTypeB(snake)) {
            cout << "B" << endl;
        } else {
            cout << "NA" << endl;
        }
    }
    
    return 0;
}