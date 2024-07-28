#include <iostream>
#include <string>

using namespace std;

// �N�r�Ź�Ӫ�s�x�b�Ʋդ�
const string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

char findCorrectChar(char c) {
    // �b��L�W��쥿�T���r��
    size_t pos = keyboard.find(c);
    if (pos != string::npos) {
        return keyboard[pos - 1];
    }
    return c;
}

int main() {
    string line;
    while (getline(cin, line)) {
        // ��C�Ӧr�Ŷi������ÿ�X
        for (char c : line) {
            cout << findCorrectChar(c);
        }
        cout << endl;
    }
    return 0;
}
