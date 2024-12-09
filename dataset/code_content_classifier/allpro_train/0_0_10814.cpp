#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
    string input;
    
    while(getline(cin, input)) {
        if(input == "END OF INPUT") {
            break;
        }
        
        istringstream iss(input);
        string word;
        string output = "";
        
        while(iss >> word) {
            output += to_string(word.length());
        }
        
        cout << output << endl;
    }
    
    return 0;
}