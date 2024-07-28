#include <iostream>
#include <string>

using namespace std;

// 將字符對照表存儲在數組中
const string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

char findCorrectChar(char c) {
    // 在鍵盤上找到正確的字符
    size_t pos = keyboard.find(c);
    if (pos != string::npos) {
        return keyboard[pos - 1];
    }
    return c;
}

int main() {
    string line;
    while (getline(cin, line)) {
        // 對每個字符進行替換並輸出
        for (char c : line) {
            cout << findCorrectChar(c);
        }
        cout << endl;
    }
    return 0;
}
