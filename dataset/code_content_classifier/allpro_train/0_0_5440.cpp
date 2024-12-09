#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    
    while(getline(cin, input)) {
        stringstream ss(input);
        string token;
        
        int studentID;
        double weight, height;
        
        getline(ss, token, ',');
        studentID = stoi(token);
        
        getline(ss, token, ',');
        weight = stod(token);
        
        getline(ss, token, ',');
        height = stod(token);
        
        double bmi = weight / (height * height);
        
        if(bmi >= 25) {
            cout << studentID << endl;
        }
    }
    
    return 0;
}