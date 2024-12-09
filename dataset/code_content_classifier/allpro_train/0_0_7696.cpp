#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> text;
    string line;

    // Read the input text
    while (getline(cin, line) && line != "END_OF_TEXT") {
        text.push_back(line);
    }

    int cursor_line = 0;
    int cursor_pos = 0;
    string buffer;

    string command;
    while (cin >> command && command != "-") {
        if (command == "a") {
            cursor_pos = 0;
        } else if (command == "e") {
            cursor_pos = text[cursor_line].size();
        } else if (command == "p") {
            cursor_line = max(0, cursor_line - 1);
            cursor_pos = 0;
        } else if (command == "n") {
            cursor_line = min(cursor_line + 1, (int)text.size() - 1);
            cursor_pos = 0;
        } else if (command == "f") {
            if (cursor_pos < text[cursor_line].size()) {
                cursor_pos++;
            } else if (cursor_line < text.size() - 1) {
                cursor_line++;
                cursor_pos = 0;
            }
        } else if (command == "b") {
            if (cursor_pos > 0) {
                cursor_pos--;
            } else if (cursor_line > 0) {
                cursor_line--;
                cursor_pos = text[cursor_line].size();
            }
        } else if (command == "d") {
            if (cursor_pos < text[cursor_line].size()) {
                text[cursor_line].erase(cursor_pos, 1);
            } else if (cursor_line < text.size() - 1) {
                text[cursor_line] += text[cursor_line + 1];
                text.erase(text.begin() + cursor_line + 1);
            }
        } else if (command == "k") {
            if (cursor_pos == text[cursor_line].size() && cursor_line < text.size() - 1) {
                buffer = text[cursor_line + 1];
                text.erase(text.begin() + cursor_line + 1);
            } else {
                buffer = text[cursor_line].substr(cursor_pos);
                text[cursor_line] = text[cursor_line].substr(0, cursor_pos);
            }
        } else if (command == "y") {
            if (buffer.empty()) {
                continue;
            } else if (buffer == "\n") {
                text.insert(text.begin() + cursor_line + 1, "");
                text[cursor_line + 1] = buffer;
                cursor_line++;
                cursor_pos = 0;
            } else {
                text[cursor_line] = text[cursor_line].substr(0, cursor_pos) + buffer + text[cursor_line].substr(cursor_pos);
                cursor_pos += buffer.size();
                buffer = "";
            }
        }
    }

    // Print the edited text
    for (const string& line : text) cout << line << endl;

    return 0;
}