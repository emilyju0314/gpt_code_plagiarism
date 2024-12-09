#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string expandAddress(const std::string &address) {
    std::vector<std::string> blocks;
    std::stringstream ss(address);
    std::string token;
    while (std::getline(ss, token, ':')) {
        blocks.push_back(token);
    }

    std::string fullAddress;
    int zerosToInsert = 8 - blocks.size();
    bool hasInserted = false;
    for (const auto &block : blocks) {
        if (!block.empty()) {
            if (zerosToInsert > 0 && hasInserted) {
                fullAddress += ":";
                --zerosToInsert;
            }
            fullAddress += block;
            hasInserted = true;
        } else {
            while (zerosToInsert > 0) {
                fullAddress += "0000";
                --zerosToInsert;
                if (zerosToInsert > 0) {
                    fullAddress += ":";
                }
            }
        }
        if (zerosToInsert > 0) {
            fullAddress += ":";
        }
    }

    while (zerosToInsert > 0) {
        fullAddress += "0000";
        --zerosToInsert;
        if (zerosToInsert > 0) {
            fullAddress += ":";
        }
    }

    return fullAddress;
}

int main() {
    int n;
    std::cin >> n;
    std::string address;
    std::getline(std::cin, address); // Consume newline

    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, address);
        std::string fullAddress = expandAddress(address);
        std::cout << fullAddress << std::endl;
    }

    return 0;
}