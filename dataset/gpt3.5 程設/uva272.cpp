#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    bool open_quote = true; // ��ܬO�_���Ӵ��J�}�l�޸�

    while (getline(cin, line)) {
        for (char c : line) {
            if (c == '"') {
                if (open_quote) {
                    cout << "``";
                }
                else {
                    cout << "''";
                }
                open_quote = !open_quote;
            }
            else {
                cout << c;
            }
        }
        cout << endl;
    }

    return 0;
}
