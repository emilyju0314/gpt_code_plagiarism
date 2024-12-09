#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string ticket;
    cin >> n >> ticket;

    int sum_first_half = 0, sum_second_half = 0;
    int question_marks = 0;

    for(int i = 0; i < n/2; i++) {
        if(ticket[i] == '?') question_marks++;
        else sum_first_half += ticket[i] - '0';
    }

    for(int i = n/2; i < n; i++) {
        if(ticket[i] == '?') question_marks++;
        else sum_second_half += ticket[i] - '0';
    }

    if(sum_first_half == sum_second_half) {
        cout << "Bicarp" << endl;
    } else {
        if(question_marks % 2 == 0) {
            cout << "Bicarp" << endl;
        } else {
            cout << "Monocarp" << endl;
        }
    }

    return 0;
}