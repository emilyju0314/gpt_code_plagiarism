#include <iostream>
#include <string>

int main() {
    int n;
    std::string record;
    
    // Input
    std::cin >> n >> record;
    
    // Find the first and last occurrence of 1
    int first_one = record.find('1');
    int last_one = record.rfind('1');
    
    // Check if all the intervals between successive signals are equal
    bool is_extra_terrestrial = true;
    int interval = last_one - first_one;
    for(int i = first_one; i <= last_one; i++) {
        if(record[i] == '1' && record[i+interval] != '1') {
            is_extra_terrestrial = false;
            break;
        }
    }
    
    // Output
    if(is_extra_terrestrial) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}