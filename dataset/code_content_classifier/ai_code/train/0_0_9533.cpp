#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // Calculate the maximum possible number of notes Lesha can read
    int n = (int)((-1 + sqrt(1 + 8.0 * a)) / 2);
    int m = (int)((-1 + sqrt(1 + 8.0 * b)) / 2);

    // Find the notes to read on the first day
    vector<int> first_day;
    for (int i = n; i > 0; i--) {
        if (a >= i) {
            first_day.push_back(i);
            a -= i;
        }
    }

    // Find the notes to read on the second day
    vector<int> second_day;
    for (int i = m; i > 0; i--) {
        if (b >= i) {
            second_day.push_back(i);
            b -= i;
        }
    }

    // Output the results
    cout << first_day.size() << '\n';
    for (int note : first_day) {
        cout << note << ' ';
    }
    cout << '\n';

    cout << second_day.size() << '\n';
    for (int note : second_day) {
        cout << note << ' ';
    }
    cout << '\n';

    return 0;
}