#include <iostream>
#include <string>
#include <vector>

void forwardChar(std::string &text, int &cursor) {
    if (cursor < text.length()) {
        cursor++;
    }
}

void forwardWord(std::string &text, int &cursor) {
    if (cursor < text.length()) {
        cursor = text.find_first_not_of(" ", cursor + 1);
        if (cursor == std::string::npos) {
            cursor = text.length();
        }
    }
}

void backwardChar(std::string &text, int &cursor) {
    if (cursor > 0) {
        cursor--;
    }
}

void backwardWord(std::string &text, int &cursor) {
    if (cursor > 0) {
        cursor = text.find_last_not_of(" ", cursor - 1);
        if (cursor == std::string::npos) {
            cursor = 0;
        }
    }
}

void insertText(std::string &text, int &cursor, std::string newText) {
    text.insert(cursor, newText);
    cursor += newText.length();
}

void deleteChar(std::string &text, int &cursor) {
    if (cursor < text.length()) {
        text.erase(cursor, 1);
    }
}

void deleteWord(std::string &text, int &cursor) {
    int start = text.find_last_not_of(" ", cursor - 1);
    if (start == std::string::npos) {
        start = 0;
    } else {
        start += 1;
    }
    int end = text.find_first_of(" ", cursor);
    if (end == std::string::npos) {
        end = text.length();
    }
    text.erase(start, end - start);
    cursor = start;
}

int main() {
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::string text;
        std::cin.ignore();
        std::getline(std::cin, text);
        
        int cursor = 0;
        
        int m;
        std::cin >> m;
        
        std::vector<std::pair<std::string, std::string>> commands;
        
        for (int j = 0; j < m; j++) {
            std::string command, argument;
            std::cin >> command;
            
            if (command == "insert") {
                std::cin.ignore();
                std::getline(std::cin, argument, '"');
            } else {
                std::cin >> argument;
            }
            
            commands.push_back({command, argument});
        }
        
        for (auto command : commands) {
            if (command.first == "forward" && command.second == "char") {
                forwardChar(text, cursor);
            } else if (command.first == "forward" && command.second == "word") {
                forwardWord(text, cursor);
            } else if (command.first == "backward" && command.second == "char") {
                backwardChar(text, cursor);
            } else if (command.first == "backward" && command.second == "word") {
                backwardWord(text, cursor);
            } else if (command.first == "insert") {
                insertText(text, cursor, command.second);
            } else if (command.first == "delete" && command.second == "char") {
                deleteChar(text, cursor);
            } else if (command.first == "delete" && command.second == "word") {
                deleteWord(text, cursor);
            }
        }
        
        text.insert(cursor, "^");
        std::cout << text << std::endl;
    }

    return 0;
}