#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    string ad;
    getline(cin, ad);
    cin >> k;

    vector<string> words;
    string word = "";
    for (char c : ad) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    words.push_back(word);

    int width = 0;
    int current_line = 1;
    for (string word : words) {
        int hyphen_index = word.find('-');
        if (width + word.size() <= k) {
            width += word.size();
        } else {
            current_line++;
            width = word.size() - hyphen_index;
        }
    }

    cout << current_line << endl;

    return 0;
}