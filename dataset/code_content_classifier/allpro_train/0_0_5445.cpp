#include <iostream>
#include <string>
#include <vector>

bool isNumber(const std::string& s) {
    return !s.empty() && s.find_first_not_of("0123456789") == std::string::npos;
}

bool isIdentifier(const std::string& s) {
    return !s.empty() && s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}

bool isValidIndex(int index, int length) {
    return index >= 0 && index < length;
}

int main() {
    std::string line;
    
    int line_number = 1;
    while (true) {
        std::vector<std::string> declared_arrays;
        std::vector<int> array_lengths;
        std::vector<std::vector<int>> array_elements;
        
        while (true) {
            std::getline(std::cin, line);
            if (line == ".")
                break;
            
            if (line.find("=") == std::string::npos) {
                int length = std::stoi(line.substr(line.find("[") + 1, line.find("]") - line.find("[") - 1));
                declared_arrays.push_back(line.substr(0, line.find("[")));
                array_lengths.push_back(length);
                
                std::vector<int> elements(length, -1);
                array_elements.push_back(elements);
            } else {
                std::string lhs = line.substr(0, line.find("="));
                std::string rhs = line.substr(line.find("=") + 1);
                
                int array_index = std::stoi(lhs.substr(lhs.find("[") + 1, lhs.find("]") - lhs.find("[") - 1));
                std::string array_name = lhs.substr(0, lhs.find("["));
                
                bool invalid_index = false;
                if (!isIdentifier(array_name) || !isValidIndex(array_index, array_lengths[declared_arrays.size() - 1])) {
                    std::cout << line_number << std::endl;
                    invalid_index = true;
                    break;
                }
                
                if (rhs.find("[") != std::string::npos) {
                    int elem_index = std::stoi(rhs.substr(rhs.find("[") + 1, rhs.find("]") - rhs.find("[") - 1));
                    std::string elem_array = rhs.substr(0, rhs.find("["));
                    
                    if (!isIdentifier(elem_array) || !isValidIndex(elem_index, array_lengths[declared_arrays.size() - 1])) {
                        std::cout << line_number << std::endl;
                        invalid_index = true;
                        break;
                    }
                    
                    if (array_elements[declared_arrays.size() - 1][elem_index] == -1) {
                        std::cout << line_number << std::endl;
                        invalid_index = true;
                        break;
                    }
                }
                
                if (!invalid_index) {
                    array_elements[declared_arrays.size() - 1][array_index] = 0;
                }
            }
            
            line_number++;
        }
        
        if (declared_arrays.empty())
            break;
    }
    
    return 0;
}