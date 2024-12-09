#include <iostream>
using namespace std;

// Function to convert a single digit number to word
string digitToWord(int digit) {
    switch(digit) {
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        default:
            return "";
    }
}

// Function to convert a two digit number to word
string convertToWord(int num) {
    if (num < 10) {
        return digitToWord(num);
    } else if (num < 20) {
        switch(num) {
            case 10:
                return "ten";
            case 11:
                return "eleven";
            case 12:
                return "twelve";
            case 13:
                return "thirteen";
            case 14:
                return "fourteen";
            case 15:
                return "fifteen";
            case 16:
                return "sixteen";
            case 17:
                return "seventeen";
            case 18:
                return "eighteen";
            case 19:
                return "nineteen";
        }
    } else {
        int tens = num / 10;
        int ones = num % 10;
        string result = "";
        switch(tens) {
            case 2:
                result += "twenty";
                break;
            case 3:
                result += "thirty";
                break;
            case 4:
                result += "forty";
                break;
            case 5:
                result += "fifty";
                break;
            case 6:
                result += "sixty";
                break;
            case 7:
                result += "seventy";
                break;
            case 8:
                result += "eighty";
                break;
            case 9:
                result += "ninety";
                break;
        }
        if (ones != 0) {
            result += "-";
            result += digitToWord(ones);
        }
        return result;
    }
}

int main() {
    int score;
    cin >> score;

    cout << convertToWord(score) << endl;

    return 0;
}