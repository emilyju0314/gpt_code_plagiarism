#include <iostream>
#include <vector>
#include <string>

int countCells(const std::string& s, size_t& pos) {
    int count = 0;
    
    if (s[pos] == '<' && s[pos+1] == 't' && s[pos+2] == 'd') {
        pos += 4; // Skip "<td>"
        while (s[pos] != '<') {
            if (s[pos] == 't' && s[pos+1] == 'd') {
                count += countCells(s, pos);
            } else {
                pos++;
                count++;
            }
        }
        pos += 5; // Skip "</td>"
    } else if (s[pos] == '<' && s[pos+1] == 't' && s[pos+2] == 'a') {
        pos += 7; // Skip "<table>"
        while (s[pos] != '<' || (s[pos] == '<' && s[pos+1] == '/' && s[pos+2] == 't' && s[pos+3] == 'a')) {
            count += countCells(s, pos);
        }
        pos += 9; // Skip "</table>"
    }
    
    return count;
}

int main() {
    std::string s, input;
    
    while (std::getline(std::cin, input)) {
        s += input;
    }
    
    std::vector<int> tableSizes;
    size_t pos = 0;
    while (pos < s.length()) {
        tableSizes.push_back(countCells(s, pos));
    }
    
    std::sort(tableSizes.begin(), tableSizes.end());
    for (int size : tableSizes) {
        std::cout << size << " ";
    }
    
    return 0;
}