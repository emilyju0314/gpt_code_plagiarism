#include <iostream>
#include <vector>
#include <string>

void formatThreadView(const std::vector<std::string>& thread) {
    for (const std::string& line : thread) {
        int depth = 0;
        for (char c : line) {
            if (c == '.') {
                depth++;
            } else {
                break;
            }
        }
        
        std::string formattedLine;
        for (int i = 0; i < depth; i++) {
            if (i == depth - 1) {
                formattedLine += "+";
            } else {
                formattedLine += " ";
            }
        }
        
        for (size_t i = depth + 1; i < line.size(); i++) {
            if (line[i] == '.') {
                formattedLine += "|";
                for (size_t j = i + 1; j < line.size(); j++) {
                    if (line[j] == '.') {
                        i = j - 1;
                    } else {
                        break;
                    }
                }
            } else {
                formattedLine += line[i];
            }
        }
        
        std::cout << formattedLine << std::endl;
    }
}

int main() {
    int n;
    std::vector<std::string> thread;

    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }

        thread.clear();
        std::cin.ignore(); // clear the newline character
        for (int i = 0; i < n; i++) {
            std::string line;
            std::getline(std::cin, line);
            thread.push_back(line);
        }

        formatThreadView(thread);
        std::cout << std::endl;
    }

    return 0;
}