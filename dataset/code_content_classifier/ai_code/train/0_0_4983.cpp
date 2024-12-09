#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string input;
    cin.ignore();
    getline(cin, input);
    
    int longest_word_outside = 0;
    int words_inside = 0;
    
    stack<int> parentheses;
    bool inside_parentheses = false;
    int current_word_length = 0;
    
    for(char c : input) {
        if(c == '(') {
            inside_parentheses = true;
            parentheses.push(current_word_length);
            current_word_length = 0;
        } else if(c == ')') {
            inside_parentheses = false;
            if(current_word_length > 0) {
                words_inside++;
            }
            current_word_length = parentheses.top();
            parentheses.pop();
        } else if(c == '_' || c == ' ') {
            if(!inside_parentheses && current_word_length > 0) {
                longest_word_outside = max(longest_word_outside, current_word_length);
            } else if(inside_parentheses && current_word_length > 0) {
                words_inside++;
            }
            current_word_length = 0;
        } else {
            current_word_length++;
        }
    }
    
    if(!inside_parentheses && current_word_length > 0) {
        longest_word_outside = max(longest_word_outside, current_word_length);
    } else if(inside_parentheses && current_word_length > 0) {
        words_inside++;
    }
    
    cout << longest_word_outside << " " << words_inside << endl;
    
    return 0;
}