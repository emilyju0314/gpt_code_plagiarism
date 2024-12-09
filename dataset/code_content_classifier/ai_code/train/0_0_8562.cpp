#include <iostream>
#include <string>
#include <vector>

using namespace std;

int calculateVotes(string district) {
    int sum = 0;
    
    if(district[0] == '[') {
        int left = 0, right = 0;
        vector<string> subDistricts;
        for(int i = 1; i < district.size() - 1; i++) {
            if(district[i] == '[') {
                left = i;
            } else if(district[i] == ']') {
                right = i;
                subDistricts.push_back(district.substr(left, right - left + 1));
            }
        }
        
        for(string sub : subDistricts) {
            sum += calculateVotes(sub);
        }
    } else {
        for(int i = 1; i < district.size() - 1; i++) {
            sum = sum * 10 + (district[i] - '0');
        }
    }
    
    return sum;
}

int main() {
    int n;
    cin >> n;
    
    cin.ignore(); // Ignore newline character
    
    while(n--) {
        string district;
        getline(cin, district);
        
        int votes = calculateVotes(district);
        cout << votes << endl;
    }
    
    return 0;
}