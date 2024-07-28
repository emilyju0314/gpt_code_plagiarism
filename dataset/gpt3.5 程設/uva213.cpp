#include <iostream>
#include <string>
#include <bitset>

using namespace std;

// 解碼器函數
void decode(string code, string& dictionary, int& idx) {
    while (true) {
        string code_fragment = code.substr(idx, 3);
        if (code_fragment == "000") // 終止條件
            break;

        int code_length = stoi(code_fragment, nullptr, 2);
        idx += 3; // 移動索引到下一個片段
        while (code_length > 0) {
            cout << dictionary[idx];
            code_length--;
        }
        idx++; // 移動索引到下一個片段的開始
    }
}

int main() {
    string dictionary = "";
    char c;

    // 讀入字典
    while (cin.get(c) && c != '\n')
        dictionary += c;

    string code;
    // 讀入編碼
    while (cin >> code) {
        int idx = 0;
        decode(code, dictionary, idx);
        cout << endl;
    }

    return 0;
}
