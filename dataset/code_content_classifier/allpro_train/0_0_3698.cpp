#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
    }

    int count = 0;
    int curr_inflorescence = 1;
    while (curr_inflorescence < n) {
        curr_inflorescence = p[curr_inflorescence];
        count++;
    }

    cout << count << endl;

    return 0;
}