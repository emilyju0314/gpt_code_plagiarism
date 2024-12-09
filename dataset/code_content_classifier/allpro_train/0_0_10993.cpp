#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string decrypt(string input) {
    string output = "";
    int index = 0;

    while (index < input.length()) {
        if (input[index] == '[') {
            index++;
            string sub_string = "";
            while (input[index] != ']') {
                sub_string += input[index];
                index++;
            }
            index++;
            reverse(sub_string.begin(), sub_string.end());
            output += decrypt(sub_string);
        } else if (input[index] == '+' || input[index] == '-') {
            char direction = input[index];
            index++;
            char letter = input[index];
            if (letter == '?') {
                char decrypted_letter = 'A'; 
                for (char c = 'A'; c <= 'Z'; c++) {
                    if (direction == '+') {
                        if (c > output.back() && (input[index+1] == c || input[index+1] == '?')) {
                            decrypted_letter = c;
                            break;
                        }
                    } else if (direction == '-') {
                        if (c < output.back() && (input[index+1] == c || input[index+1] == '?')) {
                            decrypted_letter = c;
                            break;
                        }
                    }
                }
                output += decrypted_letter;
            } else {
                output += letter;
            }
            index++;
        }
    }

    return output;
}

int main() {
    string input;
    while (getline(cin, input) && input != ".") {
        cout << decrypt(input) << endl;
    }

    return 0;
}