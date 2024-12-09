#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for(char c : s) {
        freq[c]++;
    }

    vector<string> palindromes;
    string current;

    for(auto& pair : freq) {
        char c = pair.first;
        int count = pair.second;

        if(count % 2 == 1) {
            current += c;
            count--;
        }

        for(int i = 0; i < count / 2; i++) {
            current = c + current + c;
        }

        if(current.size() > 0) {
            palindromes.push_back(current);
            current = "";
        }
    }

    cout << palindromes.size() << endl;
    for(string palindrome : palindromes) {
        cout << palindrome << " ";
    }

    return 0;
}