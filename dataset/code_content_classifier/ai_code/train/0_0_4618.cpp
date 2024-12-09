#include<iostream>
#include<string>

using namespace std;

int main() {
    string events;
    cin >> events;

    int balance = 0;
    int minPeople = 0;

    for(char c : events) {
        if(c == '+') {
            balance++;
        } else {
            if(balance == 0) {
                minPeople++;
            } else {
                balance--;
            }
        }
    }

    cout << minPeople + balance << endl;

    return 0;
}