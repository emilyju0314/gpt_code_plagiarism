#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer;
    for(int i = 2; i <= n; i *= 2) {
        cout << "B " << i << endl;
        fflush(stdout);

        cin >> answer;
        if(answer > 0) {
            for(int j = i*2; j <= n; j += i) {
                cout << "A " << j << endl;
                fflush(stdout);
                int temp;
                cin >> temp;
            }
        }
    }

    for(int i = 2; i <= n; i *= 2) {
        cout << "A " << i << endl;
        fflush(stdout);
        cin >> answer;
        if(answer == 1) {
            cout << "C " << i << endl;
            fflush(stdout);
            break;
        }
    }

    return 0;
}