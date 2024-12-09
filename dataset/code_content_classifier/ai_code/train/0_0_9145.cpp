#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    int n;
    cin >> n;

    int i = 1;
    while(n > 5 * pow(2, i-1)) {
        n -= 5 * pow(2, i-1);
        i++;
    }

    int index = (n-1) / pow(2, i-1);
    cout << names[index] << endl;

    return 0;
}