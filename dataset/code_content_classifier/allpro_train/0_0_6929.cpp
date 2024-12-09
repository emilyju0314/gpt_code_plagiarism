#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> notes;
    for (int i = 1; i <= a; i++) {
        notes.push_back(i);
    }
    
    vector<int> notes_today;
    int sum = 0;
    for (int i = 0; i < a; i++) {
        if (sum + notes[i] <= a) {
            sum += notes[i];
            notes_today.push_back(notes[i]);
        }
    }

    vector<int> notes_tomorrow;
    for (int i = 0; i < notes.size(); i++) {
        if (find(notes_today.begin(), notes_today.end(), notes[i]) == notes_today.end()) {
            notes_tomorrow.push_back(notes[i]);
        }
    }

    cout << notes_today.size() << endl;
    for (int i = 0; i < notes_today.size(); i++) {
        cout << notes_today[i] << " ";
    }
    cout << endl;

    cout << notes_tomorrow.size() << endl;
    for (int i = 0; i < notes_tomorrow.size(); i++) {
        cout << notes_tomorrow[i] << " ";
    }
    cout << endl;

    return 0;
}