#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int max_cookies = 1000;

    for(int i = 0; i < n; i++) {
        int possible_cookies = b[i] / a[i];
        max_cookies = min(max_cookies, possible_cookies);
    }

    int remaining_magic = k;
    for(int i = 0; i < n; i++) {
        int additional_ingredients_needed = max_cookies * a[i] - b[i];
        if(additional_ingredients_needed > 0) {
            int magic_needed = (additional_ingredients_needed + 1) / 2;
            remaining_magic = max(remaining_magic - magic_needed, 0);
        }
    }

    max_cookies += remaining_magic;

    cout << max_cookies << endl;

    return 0;
}