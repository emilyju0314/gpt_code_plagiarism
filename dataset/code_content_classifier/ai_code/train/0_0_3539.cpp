#include <iostream>
#include <vector>
using namespace std;

void generateAbbreviatedNotation(vector<int> pages) {
    int n = pages.size();
    int start = pages[0];
    int end = pages[0];

    for (int i = 1; i < n; i++) {
        if (pages[i] == end + 1) {
            end = pages[i];
        } else {
            if (start != end) {
                cout << start << "-" << end << " ";
            } else {
                cout << start << " ";
            }
            start = pages[i];
            end = pages[i];
        }
    }

    if (start != end) {
        cout << start << "-" << end << endl;
    } else {
        cout << start << endl;
    }
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> pages(n);
        for (int i = 0; i < n; i++) {
            cin >> pages[i];
        }
        generateAbbreviatedNotation(pages);
    }

    return 0;
}