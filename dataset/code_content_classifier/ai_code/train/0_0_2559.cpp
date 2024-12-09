#include <iostream>
using namespace std;

int countPossiblePairs(int s, int x) {
    if((s-x)%2 != 0 || (s-x > s)){
        return 0;
    }
    int a = (s-x)/2;
    int b = s - a;
    if((a^b) == x) {
        return 2;
    } else {
        return 0;
    }
}

int main() {
    int s, x;
    cin >> s >> x;

    int count = countPossiblePairs(s, x);
    cout << count << endl;

    return 0;
}