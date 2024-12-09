#include <iostream>
#include <string>
#include <map>

std::map<std::string, char> codeTable = {
    {"101", ' '},
    {"000000", '\''},
    {"000011", ','},
    {"10010001", '-'},
    {"010001", '.'},
    {"000001", '?'},
    {"100101", 'A'},
    {"10011010", 'B'},
    {"0101", 'C'},
    {"0001", 'D'},
    {"110", 'E'},
    {"01001", 'F'},
    {"10011011", 'G'},
    {"010000", 'H'},
    {"0111", 'I'},
    {"10011000", 'J'},
    {"0110", 'K'},
    {"00100", 'L'},
    {"10011001", 'M'},
    {"10011110", 'N'},
    {"00101", 'O'},
    {"111", 'P'},
    {"10011111", 'Q'},
    {"1000", 'R'},
    {"00110", 'S'},
    {"00111", 'T'},
    {"10011100", 'U'},
    {"10011101", 'V'},
    {"000010", 'W'},
    {"10010010", 'X'},
    {"10010011", 'Y'},
    {"10010000", 'Z'}
};

std::string convertToCode(std::string text) {
    std::string result;
    for (int i = 0; i < text.length(); i++) {
        std::string seq;
        while (i < text.length() && seq.length() < 5) {
            seq += text[i];
            i++;
        }
        i--;

        if (seq.length() < 5) {
            int diff = 5 - seq.length();
            for (int j = 0; j < diff; j++) {
                seq += '0';
            }
        }

        result += codeTable[seq];
    }
    return result;
}

int main() {
    std::string input;
    while (std::getline(std::cin, input)) {
        std::cout << convertToCode(input) << std::endl;
    }
    return 0;
}