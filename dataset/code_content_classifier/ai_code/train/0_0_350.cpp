#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<long long> swords(n);
    for(int i = 0; i < n; i++) {
        std::cin >> swords[i];
    }
    
    // Find the minimum number of swords in the basement
    long long min_swords = *std::min_element(swords.begin(), swords.end());
    
    // Find the total number of stolen swords
    long long total_stolen = 0;
    for(int i = 0; i < n; i++) {
        total_stolen += swords[i] - min_swords;
    }
    
    // Find the greatest common divisor of all stolen swords
    long long gcd = std::__gcd(swords[0] - min_swords, swords[1] - min_swords);
    for(int i = 2; i < n; i++) {
        gcd = std::__gcd(gcd, swords[i] - min_swords);
    }
    
    // Calculate the minimum number of people and stolen swords per person
    long long people = total_stolen / gcd;
    long long stolen_per_person = gcd;
    
    std::cout << people << " " << stolen_per_person << std::endl;
    
    return 0;
}