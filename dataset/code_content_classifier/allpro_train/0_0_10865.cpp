#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    string display;
    cin >> display;

    vector<int> min_display(n, 0);

    for(int i = 0; i < n; i++) {
        min_display[i] = display[i] - '0';
    }

    for(int i = 0; i < n; i++) {
        min_display[i] %= 10;
        for(int j = 0; j < n; j++) {
            min_display[j] = min(min_display[j], (min_display[(j-1+n)%n] + 1) % 10);
        }
    }

    for(int i = 0; i < n; i++) {
        cout << min_display[i];
    }

    return 0;
}