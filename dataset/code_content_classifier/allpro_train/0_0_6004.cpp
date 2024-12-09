#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    cin.ignore(); // to clear the input buffer
    
    for (int i = 0; i < n; i++) {
        string sentence;
        getline(cin, sentence);
        
        bool is_freda = false;
        bool is_rainbow = false;
        
        // Check if sentence ends with "lala."
        if (sentence.size() >= 5 && sentence.substr(sentence.size() - 5) == "lala.") {
            is_freda = true;
        }
        
        // Check if sentence starts with "miao."
        if (sentence.size() >= 5 && sentence.substr(0, 5) == "miao.") {
            is_rainbow = true;
        }
        
        if (is_freda && !is_rainbow) {
            cout << "Freda's" << endl;
        } else if (is_rainbow && !is_freda) {
            cout << "Rainbow's" << endl;
        } else {
            cout << "OMG>.< I don't know!" << endl;
        }
    }
    
    return 0;
}