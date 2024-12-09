#include <iostream>
using namespace std;

int main() {
    int N, s, t;
    cin >> N >> s >> t;

    cout << "? " << N << " " << s << endl; // ask the distance between N and s
    cout.flush();
    int distance1;
    cin >> distance1;

    cout << "? " << s << " " << t << endl; // ask the distance between s and t
    cout.flush();
    int distance2;
    cin >> distance2;

    cout << "? " << N << " " << t << endl; // ask the distance between N and t
    cout.flush();
    int distance3;
    cin >> distance3;

    // find the shortest path
    if (distance1 < distance2 && distance1 < distance3) {
        cout << "! " << N << " " << s << " " << t << endl;
    } else if (distance2 < distance1 && distance2 < distance3) {
        cout << "! " << s << " " << t << endl;
    } else {
        cout << "! " << N << " " << t << endl;
    }

    return 0;
}