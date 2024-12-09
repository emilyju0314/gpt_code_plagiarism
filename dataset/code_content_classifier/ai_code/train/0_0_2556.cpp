#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> university(n, 0);
    vector<int> military(n, 0);
    vector<int> students(n, 0);

    unordered_map<int, int> dormitories;

    for (int i = 0; i < m; i++) {
        char type;
        int x, y;
        cin >> type;

        if (type == 'U') {
            int a, b;
            cin >> a >> b;

            for (int j = 0; j < n; j++) {
                if (university[j] == b) {
                    university[j] = a;
                }
            }
        } 
        else if (type == 'M') {
            int c, d;
            cin >> c >> d;
            
            for (int j = 0; j < n; j++) {
                if (military[j] == d) {
                    military[j] = c;
                }
            }
        } 
        else if (type == 'A') {
            cin >> x;
            students[x-1] += dormitories[university[x-1]];
        } 
        else if (type == 'Z') {
            cin >> y;
            for (int j = 0; j < n; j++) {
                if (military[j] == y) {
                    students[j] = 0;
                }
            }
        } 
        else if (type == 'Q') {
            cin >> x;
            cout << students[x-1] << endl;
        }
    }

    return 0;
}