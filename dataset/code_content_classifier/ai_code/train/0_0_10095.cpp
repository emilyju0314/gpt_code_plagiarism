#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string marks;
    cin >> marks;

    vector<int> toffees(n, 1);

    for (int i = 0; i < n - 1; i++) {
        if (marks[i] == 'L') {
            toffees[i]++;
        } else if (marks[i] == 'R') {
            toffees[i + 1]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << toffees[i] << " ";
    }
    cout << endl;

    return 0;
}