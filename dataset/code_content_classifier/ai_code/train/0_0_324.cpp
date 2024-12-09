#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, char> conversionTable = {
        {"11", 'a'}, {"12", 'b'}, {"13", 'c'}, {"14", 'd'}, {"15", 'e'}, {"16", 'f'}, {"21", 'g'}, {"22", 'h'}, {"23", 'i'}, {"24", 'j'}, {"25", 'k'},
        {"26", 'l'}, {"31", 'm'}, {"32", 'n'}, {"33", 'o'}, {"34", 'p'}, {"35", 'q'}, {"36", 'r'}, {"41", 's'}, {"42", 't'}, {"43", 'u'}, {"44", 'v'},
        {"45", 'w'}, {"46", 'x'}, {"51", 'y'}, {"52", 'z'}, {"53", '.'}, {"54", '?'}, {"55", '!'}, {"56", ' '}
    };

    std::string input;
    while(std::getline(std::cin, input)) {
        std::string output = "";
        for(size_t i = 0; i < input.length(); i+=2) {
            std::string key = input.substr(i, 2);
            if(conversionTable.find(key) != conversionTable.end()) {
                output += conversionTable[key];
            } else {
                output = "NA";
                break;
            }
        }
        std::cout << output << std::endl;
    }

    return 0;
}