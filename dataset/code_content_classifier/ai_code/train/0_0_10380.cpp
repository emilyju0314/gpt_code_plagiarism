#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    int morning, afternoon;

    for (int i = 1; i <= 9; i++) {
        cin >> name >> morning >> afternoon;
        int total_visitors = morning + afternoon;
        int income = morning * 200 + afternoon * 300;
        cout << name << " " << total_visitors << " " << income << endl;
    }

    return 0;
}