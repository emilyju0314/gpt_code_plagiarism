#include <iostream>
#include <vector>

using namespace std;

string generateNote(const vector<string>& data) {
    string note = "";
    for (int i = 0; i < data.size(); i++) {
        note += data[i];
    }
    return note;
}

int main() {
    string operation;
    cin >> operation;

    if (operation == "Alice") {
        vector<string> a(100);
        for (int i = 0; i < 100; i++) {
            cin >> a[i];
        }
        string X = generateNote(a);
        cout << X << endl;
    } else if (operation == "Bob") {
        vector<string> b(100);
        for (int i = 0; i < 100; i++) {
            cin >> b[i];
        }
        string Y = generateNote(b);
        cout << Y << endl;
    } else if (operation == "Charlie") {
        string X, Y;
        vector<string> c(100);
        cin >> X >> Y;
        for (int i = 0; i < 100; i++) {
            cin >> c[i];
        }
        
        vector<pair<int, int>> answers;
        for (int i = 0; i < 100; i++) {
            int x, y;
            // Your strategy for finding x and y based on X, Y and c[i]
            answers.push_back({x, y});
        }

        for (int i = 0; i < 100; i++) {
            cout << answers[i].first << " " << answers[i].second << endl;
        }
    }

    return 0;
}