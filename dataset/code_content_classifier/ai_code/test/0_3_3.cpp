#include <iostream>
#include <string>
using namespace std;

int countDivisibleBy25(string s) {
    int count = 0;
    for(int i = 0; i <= 99; i++) {
        string num = to_string(i);
        if(num.size() < 2) num = "0" + num;
        
        bool valid = true;
        int index_s = s.size() - 1;
        for(int j = num.size() - 1; j >= 0; j--) {
            if(index_s >= 0 && (s[index_s] == '_' || s[index_s] == num[j])) {
                index_s--;
            } else if(s[index_s] == 'X') {
                index_s--;
                j--;
            } else {
                valid = false;
                break;
            }
        }
        
        if(index_s >= 0) valid = false;
        
        if(valid && stoi(num) % 25 == 0) {
            count++;
        }
    }
    
    return count;
}

int main() {
    string s;
    cin >> s;
    
    cout << countDivisibleBy25(s) << endl;
    
    return 0;
}