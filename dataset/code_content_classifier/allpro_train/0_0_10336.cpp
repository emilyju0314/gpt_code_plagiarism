#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool isCyclicalIsomorphic(std::string s, std::string x) {
    if(s.size() != x.size()) {
        return false;
    }
    
    // Concatenate the given string to itself to check for cyclical isomorphism
    std::string concatenated = x + x;
    
    // Check if the concatenated string contains the original string as a substring
    if(concatenated.find(s) != std::string::npos) {
        return true;
    }
    
    return false;
}

int main() {
    std::string s;
    std::cin >> s;
    
    int n;
    std::cin >> n;
    
    std::vector<std::string> queries(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> queries[i];
    }
    
    for(int i = 0; i < n; ++i) {
        std::string query = queries[i];
        int count = 0;
        
        // Iterate over all substrings of s and check for cyclical isomorphism with the current query
        for(int j = 0; j <= s.size() - query.size(); ++j) {
            std::string substring = s.substr(j, query.size());
            if(isCyclicalIsomorphic(substring, query)) {
                count++;
            }
        }
        
        std::cout << count << std::endl;
    }
    
    return 0;
}