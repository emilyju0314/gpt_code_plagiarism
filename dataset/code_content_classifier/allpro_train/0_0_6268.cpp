#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string sheets, garland;
    std::cin >> sheets >> garland;

    int max_area = 0;
    for(char c : garland) {
        int count_sheets = std::count(sheets.begin(), sheets.end(), c);

        if(count_sheets == 0) {
            max_area = -1; // if missing a color sheet, impossible to make garland
            break;
        } else {
            max_area += 1; // each sheet has area 1 sq meter
            sheets.erase(std::find(sheets.begin(), sheets.end(), c));
        }
    }

    std::cout << max_area << std::endl;
    
    return 0;
}