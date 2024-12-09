#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        string name, type;
        cin >> name >> type;
        if (type == "hard") {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}