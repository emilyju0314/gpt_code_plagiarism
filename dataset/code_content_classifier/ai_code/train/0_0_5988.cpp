#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int triplets, straights;
    cin >> triplets >> straights;
    
    int ans[n] = {0};
    
    cout << "+ 1" << endl;
    cout.flush();
    
    int newTriplets, newStraights;
    cin >> newTriplets >> newStraights;
    ans[0] = newTriplets - triplets - 1;
    triplets = newTriplets;

    cout << "+ 2" << endl;
    cout.flush();

    cin >> newTriplets >> newStraights;
    ans[1] = newTriplets - triplets;
    triplets = newTriplets;

    cout << "+ 3" << endl;
    cout.flush();

    cin >> newTriplets >> newStraights;
    ans[2] = newTriplets - triplets - 1;
    triplets = newTriplets;

    cout << "+ 1" << endl;
    cout.flush();

    cin >> newTriplets >> newStraights;
    ans[0] = newTriplets - triplets - ans[2];
    triplets = newTriplets;

    cout << "+ 4" << endl;
    cout.flush();

    cin >> newTriplets >> newStraights;
    ans[3] = newTriplets - triplets - 1;
    triplets = newTriplets;

    ans[4] = straights - newStraights;
    
    cout << "! ";
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}