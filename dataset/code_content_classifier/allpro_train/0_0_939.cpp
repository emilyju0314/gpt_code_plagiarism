#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Clear the input buffer

    for(int i=0; i<n; i++) {
        string text;
        getline(cin, text);

        for(int j=0; j<text.length()-5; j++) {
            if(text.substr(j, 6) == "Hoshino") { // Check if "Hoshino" is found
                text.replace(j, 6, "Hoshina"); // Replace "Hoshino" with "Hoshina"
            }
        }

        cout << text << endl;
    }

    return 0;
}