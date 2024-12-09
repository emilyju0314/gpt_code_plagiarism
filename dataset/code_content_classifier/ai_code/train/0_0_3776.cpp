#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sections = 1, current = 1;
    for (int i = 0; i < n; i++) {
        int next = (current + k) % n;
        if (next == 0) next = n;
        sections += next - current;
        if (sections < 2) sections = 2;
        cout << sections << " ";
        current = next;
    }

    return 0;
}