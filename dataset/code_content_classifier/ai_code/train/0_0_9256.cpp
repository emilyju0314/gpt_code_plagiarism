#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

bool isValid(std::vector<std::string>& nums) {
    int sum = 0;
    for(int i = 0; i < nums.size() - 1; i++) {
        sum += std::stoi(nums[i]);
    }
    return sum == std::stoi(nums.back());
}

int countAssignments(std::vector<std::string>& equations) {
    std::set<char> chars;
    for(const std::string& eq : equations) {
        for(char c : eq) {
            chars.insert(c);
        }
    }
    
    std::vector<char> uniqueChars(chars.begin(), chars.end());
    std::vector<int> digits;
    for(int i = 0; i < 10; i++) {
        digits.push_back(i);
    }
    
    int count = 0;
    std::vector<char> tempChars = uniqueChars;
    do {
        std::vector<std::string> nums;
        for(const std::string& eq : equations) {
            std::string temp = eq;
            for(int i = 0; i < temp.size(); i++) {
                for(int j = 0; j < uniqueChars.size(); j++) {
                    if(temp[i] == uniqueChars[j]) {
                        temp[i] = char('0' + digits[j]);
                    }
                }
            }
            nums.push_back(temp);
        }
        if(isValid(nums)) {
            count++;
        }
    } while(std::next_permutation(digits.begin(), digits.end()));
    
    return count;
}

int main() {
    int N;
    while(std::cin >> N && N != 0) {
        std::vector<std::string> equations;
        for(int i = 0; i < N; i++) {
            std::string eq;
            std::cin >> eq;
            equations.push_back(eq);
        }
        std::cout << countAssignments(equations) << std::endl;
    }
    return 0;
}