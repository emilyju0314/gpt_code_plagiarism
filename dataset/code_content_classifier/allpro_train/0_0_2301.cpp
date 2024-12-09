#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string abbreviation;
        cin >> abbreviation;

        string year_str = abbreviation.substr(4);
        int year = stoi(year_str);

        int base_year = 1989;
        while (true) {
            string base_year_str = to_string(base_year);
            if (base_year_str.find(year_str) == string::npos) {
                cout << base_year << endl;
                break;
            }
            base_year++;
        }
    }

    return 0;
}