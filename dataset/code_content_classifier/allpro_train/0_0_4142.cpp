#include <iostream>
#include <string>
#include <vector>

using namespace std;

char decryptChar(int alpha, int beta, char encrypted) {
    if (isalpha(encrypted)) {
        int gamma = encrypted - 'a';
        int gammaDecrypted = (alpha * (gamma - beta + 26)) % 26;
        return 'a' + gammaDecrypted;
    }
    return encrypted;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<pair<int, int>> keywords = {{19, 7}, {19, 8}}; // Keywords "that" and "this"

    for (int i = 0; i < n; i++) {
        string encrypted;
        getline(cin, encrypted);

        for (auto keyword : keywords) {
            int alpha = keyword.first;
            int beta = keyword.second;

            cout << "Keyword: " << (char)('a' + beta) << (char)('a' + alpha) << (char)('a' + (alpha * 13 + beta) % 26) << (char)('a' + beta) << endl;

            string decrypted = "";
            for (char c : encrypted) {
                decrypted += decryptChar(alpha, beta, c);
            }

            cout << decrypted << endl;
        }
    }

    return 0;
}