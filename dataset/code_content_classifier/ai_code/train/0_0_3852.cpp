#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }

    vector<int> programmers, mathematicians, sportsmen;
    for (int i = 0; i < n; i++) {
        if (skills[i] == 1) {
            programmers.push_back(i+1);
        } else if (skills[i] == 2) {
            mathematicians.push_back(i+1);
        } else {
            sportsmen.push_back(i+1);
        }
    }

    int teams = min(programmers.size(), min(mathematicians.size(), sportsmen.size()));

    cout << teams << endl;
    for (int i = 0; i < teams; i++) {
        cout << programmers[i] << " " << mathematicians[i] << " " << sportsmen[i] << endl;
    }

    return 0;
}