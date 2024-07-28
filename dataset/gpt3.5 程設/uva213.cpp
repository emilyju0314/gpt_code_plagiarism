#include <iostream>
#include <string>
#include <bitset>

using namespace std;

// �ѽX�����
void decode(string code, string& dictionary, int& idx) {
    while (true) {
        string code_fragment = code.substr(idx, 3);
        if (code_fragment == "000") // �פ����
            break;

        int code_length = stoi(code_fragment, nullptr, 2);
        idx += 3; // ���ʯ��ި�U�@�Ӥ��q
        while (code_length > 0) {
            cout << dictionary[idx];
            code_length--;
        }
        idx++; // ���ʯ��ި�U�@�Ӥ��q���}�l
    }
}

int main() {
    string dictionary = "";
    char c;

    // Ū�J�r��
    while (cin.get(c) && c != '\n')
        dictionary += c;

    string code;
    // Ū�J�s�X
    while (cin >> code) {
        int idx = 0;
        decode(code, dictionary, idx);
        cout << endl;
    }

    return 0;
}
